// HEADER FiLES and DECLARATION
#include <bits/stdc++.h>
using namespace std;
// This is TreeNode Class to define the tree node
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
};
// Driver code
// This is a function to initialize the new node
TreeNode *newNode(int data)
{
    TreeNode *node = new TreeNode;
    node->val = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// recursive Helper Fuction
void helper(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    ans.push_back(root->val);
    helper(root->left, ans);
    helper(root->right, ans);
}

// Pre Order Traversal Function
vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> ans;
    helper(root, ans);
    return ans;
}

int main()
{
    
    TreeNode * root = newNode(3);
    root -> left = newNode(9);
    root -> right = newNode(9);
    root -> left -> left = newNode(15);
    root -> left -> right = newNode(7);
    root -> right -> left = newNode(15);
    root -> right -> right = newNode(7);

    vector<int> ans;
    ans = preorderTraversal(root);

    // Printing ans
    for (auto n : ans)
    {
        cout << n << " ";
    }

    return 0;
}
