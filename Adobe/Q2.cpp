// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int lengthOfLongestAP(int A[], int n) {
        // code here
        if(n<=2)    return n;
        int l = 2;
        int M=INT_MIN;
        int L[n][n];
        for(int i=0;i<n;i++)
            L[i][n-1]=2;
        for(int i=n-2;i>=1;i--)
        {
            int j = i-1;
            int k = i+1;
            while(j>=0 && k<n)
            {
                if(A[j]+A[k]<2*A[i])
                    k++;
                else if(A[j]+A[k]>2*A[i])
                {
                    L[j][i]=2;
                    j--;
                }
                else
                {
                    L[j][i] = L[i][k] + 1;
                    l = max(l, L[j][i]);
                    j--;
                    k++;
                }
            }
            while(j>=0)
            {
                L[j][i]=2;
                j--;
            }
        }
        return l;
    }
    
};


// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends