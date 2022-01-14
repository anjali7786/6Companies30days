// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *A, int n, int k)
    {
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
        for(int i=k;i<n;i++)
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
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends