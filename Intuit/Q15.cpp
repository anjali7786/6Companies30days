#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(vector<int> &piles, int i)
    {
        int ans=0;
        for(int j=0;j<piles.size();j++)
        {
            ans+=(piles[j]/i);
            if(piles[j]%i!=0)
                ans++;
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int M=INT_MIN;
        for(int i=0;i<piles.size();i++)
        {
            M=max(M,piles[i]);
        }
        
        if(h<piles.size())
            return -1;
        
        else
        {
            int s=1,e=M,ans=-1;
            while(s<e)
            {
                int mid = s + (e-s)/2;
                int r = solve(piles,mid);
                if(r<=h)
                { 
                    e = mid;
                }
                else
                    s = mid+1;
            }
            return e;
            
        }
        return -1;
        
    }
};