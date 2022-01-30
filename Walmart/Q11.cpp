#include<bits/stdc++.h>
using namespace std;
long long m = 1e9+7;
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back({efficiency[i],speed[i]});
        }
        sort(v.rbegin(),v.rend());        
        priority_queue<int, vector<int>, greater<int> > pq;
        long long int sum=0,res=0;
        for(int i=0;i<n;i++)
        {
            pq.push(v[i].second);
            sum+=v[i].second;
            if(pq.size() > k)
            {
                sum-=pq.top();
                pq.pop();
            }
            res = max(res, sum*v[i].first);
            // cout<<res<<" ";
        }
        return res%m;
        
    }
};