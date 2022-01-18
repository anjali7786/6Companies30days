// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

//Function to generate binary numbers from 1 to N using a queue.
vector<string> generate(int N)
{
	// Your code here
	vector<string> ans;
	for(int i=1;i<=N;i++)
	{
	    string s="";
	    int num=i;
	    while(num)
	    {
	        s+=to_string(num%2);
	        num/=2;
	    }
	    reverse(s.begin(),s.end());
	    
	    ans.push_back(s);
	}
	return ans;
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}  // } Driver Code Ends