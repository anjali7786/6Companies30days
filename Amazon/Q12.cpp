// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        unordered_map<int,char> mp;
        for(int i=0;i<26;i++)
            mp[i+1]='A'+i;
        string ans="";
        while(n>26)
        {
            int x = n%26;
            // cout<<x<<" ";
            if(x>0) ans+=mp[x];
            else
            {
                ans+="Z";
                n--;
            }
            n/=26;
        }
        if(n>0) ans+=mp[n];
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}
  // } Driver Code Ends