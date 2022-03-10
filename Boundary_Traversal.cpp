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
bool isLeaf(TreeNode * node)
{
    if(node -> left == NULL && node -> right == NULL) return true;
    else return false;
}

vector<int> leftTraversal(TreeNode* root, vector<int> & ans){
    if(root == NULL) return ans;

    if(!isLeaf(root)) ans.push_back(root->val);
    if(root -> left != NULL) leftTraversal(root -> left, ans);
    else leftTraversal(root -> right, ans);

    return ans;    
}

int leafNodes(TreeNode * root, vector<int>& ans)
{
    if(root == NULL) return 0;

    if(isLeaf(root)) ans.push_back(root -> val);

    leafNodes(root -> left, ans);
    leafNodes(root -> right, ans);
    
    return 0;
}

vector<int> rightTraversal(TreeNode* root, vector<int> & ans){
    if(root == NULL) return ans;
    vector<int> temp;

    if(!isLeaf(root)) temp.push_back(root->val);
    if(root -> right != NULL) leftTraversal(root -> right, ans);
    else leftTraversal(root -> left, ans);

    int n = temp.size();
    for(int i = n-1; i>=0; i--)
    {
        ans.push_back(temp[i]);
    }
    return ans;    
}

vector<int> Boundary_Traversal(TreeNode * root)
{
    vector<int> ans;
    ans.push_back(root->val);
    leftTraversal(root->left, ans);
    leafNodes(root, ans);
    rightTraversal(root->right, ans);
    return ans;
}


int main() {
    
    TreeNode * root = newNode(3);
    root -> left = newNode(9);
    root -> right = newNode(20);
    root -> left -> left = newNode(9);
    root -> right -> left = newNode(15);
    root -> right -> right = newNode(7);

    vector <int> Boundary = Boundary_Traversal(root);

    for(auto i : Boundary)
        cout << i << " ";

    return 0;
}