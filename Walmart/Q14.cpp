// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the largest number after k swaps.
    void solve(string str,int k,string & t, int c)
    {
        if(k==0)    return;
        int n=str.size();
        char ma = str[c];
        for(int i=c+1;i<n;i++)
            if(str[i]>ma)
                ma=str[i];
        if(ma!=str[c])  k--;
        for(int j=n-1;j>=c;j--)
        {
            if(str[j]==ma)
            {
                swap(str[j],str[c]);
                if(str.compare(t)>0)
                    t = str;
                solve(str,k,t,c+1);
                swap(str[c], str[j]);
            }
        }
    }
    string findMaximumNum(string str, int k)
    {
       // code here
       string t ="";
       solve(str,k,t,0);
       return t;
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends