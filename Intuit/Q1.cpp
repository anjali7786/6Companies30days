#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    long long int sum=0;
	    for(int i=0;i<n;i++)
	        sum+=arr[i];
        long long int s;
        sum%2==0?s=(sum/2):s=((sum+1)/2);
        // cout<<s<<" ";
        int dp[n+1][s+1];	   
        
        for(int i=0;i<=n;i++)
            dp[i][0]=1;
        for(int i=1;i<=s;i++)
            dp[0][i]=0;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=s;j++)
            {
                if(arr[i-1]<=j)
                    dp[i][j]= (dp[i-1][j] || dp[i-1][j-arr[i-1]]);
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        
        for(int i=s;i>=0;i--)
        {
            if(dp[n][i]==1)
            {
                s=i;
                break;
            }
        }
        int s1=sum-s;
        return abs(s1-s);
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends