#include<bits/stdc++.h>
using namespace std;
int sol(vector<int> &weights, int days, int cap)
{
    int s=0,cnt=1;
    for(int i=0;i<weights.size();i++)
    {
        s+=weights[i];
        if(s>cap)
        {
            cnt++;
            s=weights[i];
        }
    }
    return cnt;
}


class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
       
        int m=-1;
        int sum=0;
        for(auto j:weights)
        {
            sum+=j;
            if(j>m)
                m=j;
        }
        int start = m, end = sum;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            int r = sol(weights, days, mid);
            if(r<=days) {
                end = mid-1;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }
};