#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
     
        int l=INT_MAX;
        int s=0,j=0;
        for(int i=0;i<nums.size();i++)
        {
            s+=nums[i];
            while(s>=target)
            {
                l = min(l,i-j+1);
                s-=nums[j];
                j++;
            }
        }
        
        if(l==INT_MAX)  return 0;
        return l;
    }
};
