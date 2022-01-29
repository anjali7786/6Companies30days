class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int ans=0;
        vector<pair<int,int>> v;
        for(int i=0;i<grid.size();i++)
        {
            int total=0;
            for(int j=grid.size()-1;j>=0;j--)
            {
                if(grid[i][j]==0)
                    total++;
                else
                    break;
            }
            v.push_back({i,total});
        }
        
        for(int t=grid.size()-1;t>0;t--)
        {
            bool u=false;
            for(int j=0;j<v.size();j++)
            {
                if(v[j].second >= t)
                {
                    u=true;
                    ans+=(v[j].first - v[0].first);
                    for(int k=0;k<j;k++)
                        v[k].first+=1;
                    v.erase(v.begin()+j);
                    break;
                }
            }
            if(u==false)
                return -1;
        }
        
        return ans;
    }
};