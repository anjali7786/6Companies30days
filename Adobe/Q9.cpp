// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    string nextPalin(string N) { 
        //complete the function here
        int size = N.size();
        string t = N.substr(0,size/2);
        if(!next_permutation(t.begin(),t.end()))
        {
            return "-1";
        }
        string s = t;
        reverse(s.begin(),s.end());
        if(size%2)
            t+=N[size/2];
        return t+s;
        
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution obj;
        cout << obj.nextPalin(s) << endl;
    }
    return 0;
}  // } Driver Code Ends