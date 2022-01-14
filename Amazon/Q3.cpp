// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> A, int n, int k) {
        
        vector<int> ans;
        int j=0;
        priority_queue< pair<int,int> > q; 
        for(int i=0;i<k;i++)
            q.push({A[i],i});
        ans.push_back(q.top().first);
        if(k==n)
        {
            return {q.top().first};
        }
        for(int i=k;i<A.size();i++)
        {
            // cout<<q.top().first<<"{}"<<q.top().second<<"{}\n";
            while(!q.empty() && q.top().second<=j)
                q.pop();
            q.push({A[i],i});
            j++;
            ans.push_back(q.top().first);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}  // } Driver Code Ends