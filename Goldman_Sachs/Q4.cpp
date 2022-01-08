// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{     
    string s = "";
    int cnt=1;
    for(int i=1;i<src.size();i++)
    {
        if(src[i]!=src[i-1])
        {
            s+=src[i-1];
            s+=to_string(cnt);
            cnt=1;
        }
        else
            cnt++;
    }
    if(cnt!=0)
    {
        s+=src[src.size()-1];
        s+=to_string(cnt);
        cnt=0;
    }
    return s;
}     
 
