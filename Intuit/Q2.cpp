// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool solve(vector<vector<char>>& board,string word,int pos,int i,int j)
    {
        int n = board.size();
        int m = board[0].size();
        if(i<0 || j<0 || i>=n || j>=m)
            return false;
        if(pos==word.size())
            return true;
        if(word[pos]==board[i][j])
        {
            char t = board[i][j];
            board[i][j]='#';
            bool a = solve(board,word,pos+1,i+1,j);
            bool b = solve(board,word,pos+1,i-1,j);
            bool c = solve(board,word,pos+1,i,j+1);
            bool d = solve(board,word,pos+1,i,j-1);
            board[i][j]=t;
            return a||b||c||d;
        }
        else
            return false;
    }
                    
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(board[i][j]==word[0])
                {
                    bool res = solve(board,word,0,i,j);
                    if(res)
                        return res;
                }
        return false;
        
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends