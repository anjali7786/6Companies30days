#include <bits/stdc++.h>
using namespace std;


int main()
{
    cout<<"Enter strings: ";
    string s,t,ans="";
    cin>>s>>t;
    int l1 = s.size(),l2=t.size();
    int i=0,j=0;
    while(i++<l1 && j++<l2)
    {
        string d1="",d2="";
        while(s[i]!='.' && i<l1)
        {
            d1+=s[i];
            i++;
        }
        while(t[j]!='.' && j<l2)
        {
            d2+=t[j];
            j++;
        }
        if(stoi(d1)>stoi(d2))
        {
            ans=s;
            break;
        }   
        else
        {
            ans=t;
            break;
        }
    }
    if(ans=="")
    {
        if(i<l1 && j>=l2)
            ans=s;
        else if(j<l2 && i>=l1)
            ans=t;
        else
            ans = "Same\n"; 
    }
    cout<<ans;
}
