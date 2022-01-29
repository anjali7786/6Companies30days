#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<int>> &isConnected, int i, int j)
    {
        isConnected[i][j]=0;
        isConnected[j][i]=0;
        
        for(int x=0;x<isConnected.size();x++)
        {
            if(isConnected[x][j]==1)
                dfs(isConnected,j,x);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
       
        int n = isConnected.size();
        int cnt=0;
        for(int i=0;i<isConnected.size();i++)
        {
            for(int j=0;j<isConnected[0].size();j++)
            {
                if(isConnected[i][j]==1)
                {
                    cnt++;
                    dfs(isConnected, i, j);
                }
            }
        }
        return cnt;
            
    }
};