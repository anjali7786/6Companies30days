// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        
        int i=0,j=0,ans=0;
        long long p = 1;
        for(i=0;i<n;i++)
        {
            p*=a[i];
            while(j<i && p>=k)
            {
                p/=a[j];
                j++;
                // cout<<"Ans: "<<ans<<"\n";
            }
            if(p<k)
                ans+=(i-j+1);
        }
        // cout<<" :: "<<ans<<"\n";
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends