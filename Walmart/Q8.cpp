// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int height(int N){
        // code here
        // n*(n+1) = 2*N;
        // n^2 + n - c=0;
        int c = 2*N;
        float x = (-1 + sqrt(1+4*c))/2;
        float y = (-1 - sqrt(1+4*c))/2;
        
        return max(floor(x),floor(y));
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.height(N)<<endl;
    }
    return 0;
}  // } Driver Code Ends