/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* solve(vector<vector<int>> &grid, int sr,int r,int sc,int c,int n)
    {
        Node* ans;
        int sum=0;
        for(int i=sr;i<r;i++)
            for(int j=sc;j<c;j++)
                sum+=grid[i][j];
        
        if(sum==0)
            ans = new Node(false,true);
        else if(sum==n*n)
            ans = new Node(true,true);
        else
        {
            ans = new Node(false,false);
            n=n/2;
            ans->topLeft = solve(grid,sr,sr+n,sc,sc+n,n);
            ans->topRight = solve(grid,sr,sr+n,sc+n,c,n);
            ans->bottomLeft = solve(grid,sr+n,r,sc,sc+n,n);
            ans->bottomRight = solve(grid,sr+n,r,sc+n,sc,n);
        }
        return ans;
    }
    
    Node* construct(vector<vector<int>>& grid) {
     
        int n=grid.size();
        return solve(grid,0,n,0,n,n);
    }
};

