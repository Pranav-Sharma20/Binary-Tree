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

// Helper recursive function
void helper(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    helper(root->left, ans);
    ans.push_back(root->val);
    helper(root->right, ans);
}
// Indorder Function
vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> ans;
    helper(root, ans);
    return ans;
}

int main()
{
    int i, j;
    TreeNode *root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    vector<int> ans;
    ans = inorderTraversal(root);

    // Printing ans
    for (auto n : ans)
    {
        cout << n << " ";
    }
    return 0;
}
