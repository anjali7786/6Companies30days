#include<bits/stdc++.h>
using namespace std;

bool valid(int x,int y,int r,int c)
{
    return (x<r && y<c && x>=0 && y>=0);
}

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
     
        int r = grid.size();
        int c = grid[0].size();
        int cnt=0;
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                    q.push({i,j});
            }
        }
        
        while(!q.empty())
        {
            cnt++;
            int s = q.size();
            while(s--)
            {    
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(valid(x-1,y,r,c))
                {
                    if(grid[x-1][y]==1)
                    {
                        grid[x-1][y]=2;
                        q.push({x-1,y});
                    }
                }
                if(valid(x,y-1,r,c))
                { 
                    if(grid[x][y-1]==1)
                    {
                        grid[x][y-1]=2;
                        q.push({x,y-1});
                    }
                }
                if(valid(x+1,y,r,c))
                {
                    if(grid[x+1][y]==1)
                    {
                        grid[x+1][y]=2;
                        q.push({x+1,y});
                    }
                }
                if(valid(x,y+1,r,c))
                {
                    if(grid[x][y+1]==1)
                    {
                        grid[x][y+1]=2;
                        q.push({x,y+1});
                    }
                }

            }
        }
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                    return -1;
            }
        }
        if(cnt==0)  return 0;
        return cnt-1;
    }
};