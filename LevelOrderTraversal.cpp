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

vector<vector<int>> levelorder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        vector<int> temp;
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            if (node->left != NULL)
                q.push(node->left);

            if (node->right)
                q.push(node->right);
            temp.push_back(node->val);
        }
        ans.push_back(temp);
    }
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

    vector<vector<int>> ans;
    ans = levelorder(root);

    // Printing ans
    for (auto n : ans)
    {
        for (auto w : n)
        {
            cout << w << " ";
        }
    }

    return 0;
}