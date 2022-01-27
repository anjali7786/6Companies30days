// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void solve(int a,int b, vector<string>& ans, string t)
    {
        if(a==0 && b==0)
        {
            ans.push_back(t);
            return;
        }
        if(a<b)
        {
            if(a>=0)
                solve(a-1,b,ans,t+'(');
            if(b>=0)
                solve(a,b-1,ans,t+')');
        }
        else if(a==b)
        {
            if(a>=0)    solve(a-1,b,ans,t+'(');
        }
        return;
    }
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        vector<string> ans;
        solve(n,n,ans,"");
        return ans;
    }
};

// { Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends