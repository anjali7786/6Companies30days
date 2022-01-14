#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        
        int n=arr.size();
        int ans=0;
        for(int i=1;i<n-1;)
        {
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
            {
                
                 int cnt=1;
                int peak=i;
                while(peak>0 && arr[peak]>arr[peak-1])
                {
                    peak--;
                    cnt++;    
                }
                while(i<n-1 && arr[i]>arr[i+1])
                {
                    i++;
                    cnt++;    
                }
                ans = max(ans,cnt);
                
            }
            else    i++;
        }
        return ans;
        
    }
};