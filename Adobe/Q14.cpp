// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


 // } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Solution{
    public:
    pair<int,int> findSmallestRange(int A[][N], int n, int k)
    {
          //code here
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>> > pq;
        int M = INT_MIN, min_range=INT_MAX,start;
        for(int i=0;i<k;i++)
        {
            pq.push({A[i][0],i});
            M=max(M,A[i][0]);
        }
        int a[k]={0};
        while(true)
        {
            auto p = pq.top();
            pq.pop();
            int mi = p.first;
            int r = M - mi;
            if(r<min_range)
            {
                start = mi;
                min_range = r;
            }
            a[p.second]++;
            if(a[p.second]==n)
                break;
            pq.push({A[p.second][a[p.second]], p.second});
            M = max(M,A[p.second][a[p.second]]);
        }
        return {start,min_range+start};
          
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}

  // } Driver Code Ends