// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
        // code here
        int t[K+1][N+1];
        for(int i=0;i<=K;i++)
        {
            for(int j=0;j<=N;j++)
            {
                if(i==0 || j==0)
                    t[i][j]=0;
            }
        }
        
        for(int i=1;i<=K;i++)
        {
            for(int j=1;j<=N;j++)
            {
                int m = INT_MIN;
                for(int k=0;k<j;k++)
                    m = max(m, A[j]-A[k]+t[i-1][k]);
                t[i][j] = max(t[i][j-1], m);
            }
        }
        return t[K][N-1];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends