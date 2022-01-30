#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        
        int n=piles.size();
        int i=0,j=n-1,cnt=0,a=0,b=0;
        while(i<=j)
        {
            if(cnt%2)
            {
                if(piles[i]>=piles[j])
                {
                    b+=piles[i];
                    i++;
                }
                else
                {
                    b+=piles[j];
                    j--;
                }
            }
            else
            {
                if(piles[i]>=piles[j])
                {
                    a+=piles[i];
                    i++;
                }
                else
                {
                    a+=piles[j];
                    j--;
                }   
            }
        }
        if(a>b) return true;
        return false;
    }
};