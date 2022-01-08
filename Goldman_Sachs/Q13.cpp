// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        // code here
        string ans = "";
        stack<char> st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=']')
                st.push(s[i]);
            else
            {
                string t = "", d = "";
                while(!st.empty() && st.top()!='[')
                {
                    t= st.top()+t;
                    st.pop();
                }
                st.pop();
                
                while(!st.empty() && isdigit(st.top()))
                {
                    d= st.top()+d;
                    st.pop();
                }
                
                int r = stoi(d);
            
                while(r--)
                {
                    for(int j=0;j<t.size();j++)
                    {
                        st.push(t[j]);
                    }
                }
            
            }
        }
        
        while(!st.empty())
        {
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends