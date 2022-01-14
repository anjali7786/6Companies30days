// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    string s="";
		    int mp[26]={0};
		    queue<int> q;
		    for(int i=0;i<A.size();i++)
	        {
	            q.push(A[i]);
	            mp[A[i]-'a']++;
	            if(mp[q.front()-'a']==1)
	                s+=q.front();
	            else
	            {
	                while(!q.empty() && mp[q.front()-'a']!=1)
	                {
	                    q.pop();
	                }
	                if(q.empty())   s+="#";
	                else    s+=q.front();
	            }
	        }
		    return s;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends