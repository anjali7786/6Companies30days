// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S){
        
        stack<int> st;
        string t="";
        for(int i=0;i<=S.size();i++)
        {
            st.push(i+1);
            if(i==S.size() || S[i]=='I')
            {
                while(!st.empty())
                {
                    t+=to_string(st.top());
                    st.pop();
                }
            }
        }
        return t;
         
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends