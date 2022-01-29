#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int N, vector<vector<int>>& prerequisites) {
        
        
        // Code here
	    vector<vector<int>> adj(N);
	    vector<int> indeg(N,0);
	    for(auto i:prerequisites)
        {
            adj[i[0]].push_back(i[1]);
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
            {
                q.push(i);
                cout<<i<<" ";
            }
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
	       return {};
	   reverse(t.begin(),t.end());
        return t; 
    }
};