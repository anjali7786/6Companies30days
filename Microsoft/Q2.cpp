// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    
	    // Code here
	    vector<vector<int>> adj(N);
	    vector<int> indeg(N,0);
	    for(auto i:prerequisites)
        {
            adj[i.first].push_back(i.second);
        }
        for(int i=0; i<N; i++) {
	        for(auto& it: adj[i]) {
	            indeg[it]++;
	        }
	    }
	    queue<int> q;
	    for(int i=0;i<N;i++)
	   {
	        if(indeg[i]==0)
	            q.push(i);
	   }
	   vector<int> t;
	   while(!q.empty())
	   {
	       int c = q.front();
	       q.pop();
	       t.push_back(c);
	       //cout<<c<<" ";
	       for(auto i : adj[c])
	       {
	            indeg[i]--;
	            if(indeg[i]==0)
	                q.push(i);
	       }
	   }
	   if(t.size()!=N)  
	       return false;
	   return true;
	    
	}
};


// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends