#include<bits/stdc++.h>
using namespace std;

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) 
    {
        int n = mountainArr.length();
        int i=0,j=n-1,peak;
        while(i<=j)
        {
            int m = i+(j-i)/2;
            int post=-1,pre=-1,e=-1;
            e = mountainArr.get(m);
            if(m-1>=0)
                pre = mountainArr.get(m-1);
            if(m+1<n)
                post = mountainArr.get(m+1);
            
            if(e>pre && e>post)
            {
                peak=m;
                if(e==target)   return m;
                break;
            }
            else if(e>pre)  i = m+1;
            else    j=m-1;
        }
        
        int l=0,h=peak-1;
        while(l<=h)
        {
            int m = l+(h-l)/2;
            int e=mountainArr.get(m);
            if(e==target)   return m;
            else if(e>target)   h = m-1;
            else    l = m+1;
        }
        
        l=peak+1,h=n-1;
        while(l<=h)
        {
            int m = l+(h-l)/2;
            int e=mountainArr.get(m);
            if(e==target)   return m;
            else if(e>target)   l = m+1;
            else    h = m-1;    
        }
        return -1;
        
        
    }
};