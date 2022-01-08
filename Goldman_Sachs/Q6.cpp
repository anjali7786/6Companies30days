#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        
        if(str1+str2 == str2+str1)
        {
            int x = __gcd(str1.size(),str2.size());
            return str1.substr(0,x);
        }
        return "";
    }
};