#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSub(vector<int>&nums, int mid)
    {
        int s=0,cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            s+=nums[i];
            if(s>mid)
            {
                s=nums[i];
                cnt++;
            }
        }
        return cnt+1;
    }
    int splitArray(vector<int>& nums, int m) {
        
        int M=INT_MIN,sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            M=max(M,nums[i]);
        }
        int s=M,e=sum,ans=-1;
        while(s<=e)
        {
            int mid = s + (e-s)/2;
            int x = minSub(nums,mid);
            if(x<=m)
            {
                ans=mid;
                e=mid-1;
            }
            else
                s=mid+1;
        }
        return ans;
    }
};