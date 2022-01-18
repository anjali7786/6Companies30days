// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int x=0;
        int flag=0;
        for(int i=0;i<str.size();i++)
        {
            char c = str[i];
            if(i==0 && str[i]=='-')
            {
                flag=1;
                continue;
            }
            if(c>='0' && c<='9')
                x = (x*10 + ((int)c - '0'));
            else
                return -1;
        }
        if(flag==1)
            return -x;
        return x;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}  // } Driver Code Ends