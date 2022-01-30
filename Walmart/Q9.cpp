#include<bits/stdc++.h>
using namespace std;

int dp[201][201];
int solve(int idx,int n)
{
    if(idx >= n) return 0;
    else if(dp[idx][n] != -1) return dp[idx][n];

    int res = INT_MAX;
    for(int i=idx;i<=n;i++){
        res = min(res,i + max(solve(i+1,n),solve(idx,i-1)));
    }

    return dp[idx][n] = res;
}
class Solution {
public:
    int getMoneyAmount(int n) {
        memset(dp,-1,sizeof dp);
        int ans = solve(1,n);
        return ans;
    }
};