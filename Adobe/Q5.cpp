// { Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

long long int t[1001][1001];
int m = 1e9+7;
class Solution{
    public:
    int solve(int n,int x,int i)
    {
        if(n==0)
            return 1;
        if(i>n)
            return 0;
        if(t[n][i]!=-1)
            return t[n][i]%m;
        long long int p = pow(i,x);
        if(p<=n)
        {
            t[n][i] = solve(n-p,x,i+1) + solve(n,x,i+1);
            return t[n][i]%m;
        }
        else
        {
            t[n][i]=0;
            return t[n][i]%m;
        }
    }
    int numOfWays(int n, int x)
    {
        // code here
        memset(t,-1,sizeof(t));
        
        return solve(n,x,1);
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}
  // } Driver Code Ends