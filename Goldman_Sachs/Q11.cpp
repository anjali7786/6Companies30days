// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        
        // code here
        int a[n+1];
        int r=0,m=0;
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++)
        {
            if(a[arr[i]]==0)    a[arr[i]]=arr[i];
            else    r=arr[i];
        }
        
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0)
            {
                m=i;
                break;
            }
        }
        int v[2];
        v[0]=r;v[1]=m;
        int *p=v;
        return p;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends