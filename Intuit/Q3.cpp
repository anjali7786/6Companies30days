// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_DIGITS = 5;

int missingNumber(const string& str);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        cout << missingNumber(str)<<endl;
    }
	return 0;
}
// } Driver Code Ends

int solve(const string &str, int i, int m)
{
    if(i+m>str.length())
        return -1;
    int v = 0;
    for(int k=0;k<m;k++)
    {
        int c = str[i+k] - '0';
        if(c>=0 && c<=9)
            v=(10*v)+c;
        else    return -1;
    }
    return v;
}

/* You are required to complete this function
which return the required missing number
if present else return -1*/
int missingNumber(const string& str)
{
    // Code here
    for(int i=1;i<=6;i++)
    {
        int n = solve(str,0,i);
        // cout<<n<<" ";
        int missing=-1;
        if(n==-1)
            break;
        int flag=false;
        for(int j=i;j!=str.length();j=(j+1+log10l(n)))
        {
            if(missing == -1 && solve(str,j,1+log10l(n+2))==n+2)
            {
                missing = n+1;
                n+=2;
            }
            else if(solve(str,j,1+log10l(n+1))==n+1)
                n++;
            else 
            {
                flag=true;
                break;
            }
        }
        if(!flag)
            return missing;
        
    }
    return -1;
}