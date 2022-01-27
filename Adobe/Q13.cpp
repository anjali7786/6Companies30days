// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    
    int minInsAndDel(int A[], int B[], int n, int m) {
        // code here
        set<int> s;
        vector<int> ans;
        for(int i=0;i<m;i++)
            s.insert(B[i]);
        for(int i=0;i<n;i++)
        {
            if(s.find(A[i])!=s.end())
            {
                int t = lower_bound(ans.begin(),ans.end(),A[i]) - ans.begin();
                if(t==ans.size())
                    ans.push_back(A[i]);
                else
                    ans[t] = A[i];
            }
        }
        return n+m - ans.size();
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M;
        cin>>N>>M;
        
        int A[N], B[M];
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<M; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.minInsAndDel(A,B,N,M) << endl;
    }
    return 0;
}  // } Driver Code Ends