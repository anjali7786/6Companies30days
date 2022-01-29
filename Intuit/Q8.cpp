#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        
        unordered_map<int , int>  mp;
        int ans=0;
        if(points.size()==1)
            return 0;
        for(int i=0;i<points.size();i++)
        {
            for(int j=0;j<points.size();j++)
            {
                if(i!=j)
                {
                    int x = (points[i][0] - points[j][0])*(points[i][0] - points[j][0]);
                    int y = (points[i][1] - points[j][1])*(points[i][1] - points[j][1]);
                    mp[x+y]++;
                }
            }
            for(auto i:mp)
            {
                int r = i.second;
                ans+=(r*(r-1));
            }
            mp.clear();
        }
        return ans;
    }
};