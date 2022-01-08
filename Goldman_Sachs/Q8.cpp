// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
	    
	    int decode(string s, int n)
	    {
	        int m=1e9+7;
	        if(s[0]=='0')
	            return 0;
	        if(n<=1)
	            return 1;
	        long long int t[n+1];
	        memset(t,0,sizeof(t));
	        t[0]=1;
	        t[1]=1;
	        for(int i=2;i<=n;i++)
	        {
	            if(s[i-1]>='1' && s[i-1]<='9')
	                t[i]=t[i-1];
	            if(s[i-2]=='1' || s[i-2]=='2' && s[i-1]<='6')
                    t[i]+=(t[i-2]%m);   
	        }
	        return t[n]%m;
	    }
		int CountWays(string str){
		    // Code here
		    
		    return decode(str,str.size());
		    
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends