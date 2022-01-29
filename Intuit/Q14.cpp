#include<bits/stdc++.h>
using namespace std;
int visited[10001][10001];
    
bool isValid(int n,int i,int j,vector<vector<int>> &grid)
{
    return (i>=0 && j>=0 && i<n && j<n && grid[i][j]==0 && visited[i][j]==0);
}
    
int bfs(vector<vector<int>> &grid, queue<pair<int,int>> & q)
{
    int cnt=0;
    int n = grid.size();
    memset(visited,0,sizeof(visited));
    while(!q.empty())
    {
        int s = q.size();
        while(s--)
        {
            int f = q.front().first;
            int s = q.front().second;
            visited[f][s]=1;
            q.pop();
            if(isValid(n,f+1,s,grid))
            {
                visited[f+1][s]=1;
                q.push({f+1,s});
            }
            if(isValid(n,f-1,s,grid))
            {
                visited[f-1][s]=1;
                q.push({f-1,s});
            }
            if(isValid(n,f,s+1,grid))
            {
                visited[f][s+1]=1;
                q.push({f,s+1});
            }
            if(isValid(n,f,s-1,grid))
            {
                visited[f][s-1]=1;
                q.push({f,s-1});
            }
        }
        cnt++;
    }
    if(cnt==1)  return -1;
    return cnt-1;
}

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
        int n=grid.size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    visited[i][j]=1;
                    q.push({i,j});
                }
            }
        }
        return bfs(grid,q);
        
    }
};