#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int divi, int div) {
        long long  t=0;
        long long quotient =0;
        long long dividend = divi;
        long long divisor = div;
        int s = ((dividend < 0)^(divisor < 0)) ? -1 : 1;
        dividend = abs(dividend);
        divisor = abs(divisor);
        for(int i=31;i>=0;i--)
        {
            if((t+(divisor<<i))<=dividend)
            {
                t+=(divisor<<i);
                quotient = (1LL<<i) | quotient;
            }
        }
        if(s==-1)   
            quotient = -quotient;
        
        if(quotient+1 > 1LL<<31)
            return (1LL<<31)-1;
        if(quotient < -1*(1LL<<31))
            return -1*(1LL<<31);
        
        return quotient;
    }
};