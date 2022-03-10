// HEADER FiLES and DECLARATION
#include<bits/stdc++.h>
using namespace std;
// This is TreeNode Class to define the tree node
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
};
// Driver code
// This is a function to initialize the new node
TreeNode * newNode(int data) {
    TreeNode * node = new TreeNode;
    node -> val = data;
    node -> left = NULL;
    node -> right = NULL;
    return node;
}

// Check function for the leaf nodes    
bool isLeaf(TreeNode * node)
{
    if(node -> left == NULL && node -> right == NULL) return true;
    else return false;
}

// Do a traversal in which just go left left and then if there is no left
// Go right then then check if it is not the leaf node 
// Insert it in the ans as it is 
void leftTraversal(TreeNode* root, vector<int> & ans){
    while(root){
        if(!isLeaf(root)) ans.push_back(root->val);
        if(root -> left != NULL) root = root -> left;
        else root = root -> right;
    }
}

// Simple preorder traversal and then check that if it is leaf node
// Then push it in the ans as it is
int leafTreeNodes(TreeNode * root, vector<int>& ans)
{
    if(root == NULL) return 0;

    if(isLeaf(root)) ans.push_back(root -> val);

    leafTreeNodes(root -> left, ans);
    leafTreeNodes(root -> right, ans);
    
    return 0;
}

// for right traversal there is just a simple trick
// we actually need opposite right traversal so just take another vector
// push all the node which are not leaf in this temp vector and then
// while pushing in actual and just take values from the back of temp
void rightTraversal(TreeNode* root, vector<int> & ans){
    vector<int> temp;
    while(root){
        if(!isLeaf(root)) temp.push_back(root->val);
        if(root -> right != NULL) root = root -> right;
        else root = root -> left;
    }
    
    for(int i = temp.size()-1; i>=0; i--)
    {
        ans.push_back(temp[i]);
    }
}


// Anti CLock wise boundary 
vector <int> boundary(TreeNode *root)
{
    vector<int> ans;
    if(!root) return ans;
    if (!isLeaf(root))ans.push_back(root->val);
    leftTraversal(root->left, ans);           // T.C. -> O(H) + O(H) + O(N)
    leafTreeNodes(root, ans);                         // ~ O(N)
    rightTraversal(root->right, ans);           
    return ans;                               // S.C. - O(N)
}


int main() {
    int i, j;
    TreeNode * root = newNode(3);
    root -> left = newNode(9);
    root -> right = newNode(20);
    root -> right -> left = newNode(15);
    root -> right -> right = newNode(7);

    vector<int> ans = boundary(root);

    for(auto i : ans)
    {
        cout << i << " ";
    }
    cout << "\n" ;
    return 0;
}