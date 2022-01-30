#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<vector<pair<int, double>>> v(n);
        for(int i=0;i<edges.size();i++)
        {
            v[edges[i][0]].push_back({edges[i][1], succProb[i]});
            v[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        
        vector<double> P(n, 0);
        queue<int> q;
        q.push(start);
        P[start] = 1;
        
        while (!q.empty()){
            int node = q.front();
            q.pop();
            for (auto i : v[node]){
                int nxt = i.first;
                double p = i.second;
                if (P[nxt] < P[node] * p)
                    P[nxt] = P[node] * p, q.push(nxt);
            }
        }
        return P[end];
        
   
    }
};