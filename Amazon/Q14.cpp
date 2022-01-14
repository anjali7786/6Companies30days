// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++
unordered_map <Node*,Node*> mp;
Node* r;
void parent_map(Node* root, int target)
{
    if(root->data==target)
        r=root;
    if(root==NULL)
        return;
    if(root->left!=NULL)
    {
        mp[root->left]=root;
        parent_map(root->left,target);
    }
    if(root->right!=NULL)
    {
        mp[root->right]=root;
        parent_map(root->right,target);
    }
}

class Solution {
  public:
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        mp.clear();
        r=NULL;
        unordered_map<Node*,int> m;
        int ans=0;
        queue<Node*> q;
        parent_map(root, target);
        // for(auto i:mp)
        //     cout<<i.first->data<<" "<<i.second->data<<"\n";

        q.push(r);
        m[r]=1;
        while(!q.empty())
        {
            int s = q.size();
            ans+=1;
            while(s--)
            {
                Node* t = q.front();
                m[t]=1;
                if(t!=root && !m[mp[t]]) q.push(mp[t]);
                if(t->left && !m[t->left]) q.push(t->left);
                if(t->right && !m[t->right])    q.push(t->right);
                q.pop();
            }
        }

        return ans-1;
        
    }
};
// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends