// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++


class Solution{
public:

    bool checkR(vector<vector<int>> &mat)
    {
        bool A[10];
        memset(A,false, sizeof(A));
        for(int i=0;i<9;i++)
        {
            memset(A,false, sizeof(A));
            for(int j=0;j<9;j++)
            {
                if(mat[i][j]>0 && mat[i][j]<=9)
                {
                    int r = mat[i][j];
                    if(A[r])    return false;
                    else    A[r]=true;
                }   
            }
        }
        return true;
    }
        
    bool checkC(vector<vector<int>> &mat)
    {
        bool A[10];
        memset(A,false, sizeof(A));
        for(int i=0;i<9;i++)
        {
            memset(A,false, sizeof(A));
            for(int j=0;j<9;j++)
            {
                if(mat[j][i]>0 && mat[j][i]<=9)
                {
                    int r = mat[j][i];
                    if(A[r])    return false;
                    else    A[r]=true;
                }   
            }
        }
        return true;
    }
    
    
    bool checkB(vector<vector<int>> &mat)
    {
        bool A[10];
        memset(A,false, sizeof(A));
        for(int i=0;i<9;i+=3)
        {
            for(int j=0;j<9;j+=3)
            {
                memset(A,false, sizeof(A));
                for(int k=0;k<3;k++)
                {
                    for(int l=0;l<3;l++)
                    {
                        int x = i+k;
                        int y = j+l;
                        if(mat[x][y]>0 && mat[x][y]<=9)
                        {
                            int r = mat[x][y];
                            if(A[r])    return false;
                            else    A[r]=true;
                        }      
                    }
                }
                
            }
        }
        return true;
    }
    
    int isValid(vector<vector<int>> mat){
        
        bool res = checkR(mat);
        
        bool res2 = checkC(mat);
        
        bool res3 = checkB(mat);   
        
        return res & res2 & res3;
    
    }
    
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends