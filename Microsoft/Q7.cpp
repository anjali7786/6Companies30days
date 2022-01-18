// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
int cnt=0;
class Solution
{
    public:
    bool isValid(int i,int j,int r,int c)
    {
        return i>=0 && j>=0 && i<r && j<c;
    }
    void ans(vector<vector<int>>& grid, int &cnt, int r,int c,int i, int j) 
    {
        if(grid[i][j]==0)
            return;
        grid[i][j]=0;
        cnt++;
        if(isValid(i+1,j,r,c))
        {
            if(grid[i+1][j]==1)
                ans(grid,cnt,r,c,i+1,j);
        }
        if(isValid(i-1,j,r,c))
        {
            if(grid[i-1][j]==1)
                ans(grid,cnt,r,c,i-1,j);
        }
        if(isValid(i,j+1,r,c))
        {
            if(grid[i][j+1]==1)
                ans(grid,cnt,r,c,i,j+1);
        }
        if(isValid(i,j-1,r,c))
        {
            if(grid[i][j-1]==1)
                ans(grid,cnt,r,c,i,j-1);
        }
        if(isValid(i+1,j+1,r,c))
        {
            if(grid[i+1][j+1]==1)
                ans(grid,cnt,r,c,i+1,j+1);
        }
        if(isValid(i-1,j-1,r,c))
        {
            if(grid[i-1][j-1]==1)
                ans(grid,cnt,r,c,i-1,j-1);
        }
        if(isValid(i-1,j+1,r,c))
        {
            if(grid[i-1][j+1]==1)
                ans(grid,cnt,r,c,i-1,j+1);
        }
        if(isValid(i+1,j-1,r,c))
        {
            if(grid[i+1][j-1]==1)
                ans(grid,cnt,r,c,i+1,j-1);
        }
        
    }
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        
        int M = INT_MIN;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                int cnt=0;
                ans(grid,cnt,grid.size(),grid[0].size(),i,j);
                M=max(M,cnt);
            }
        }
        return M;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends