//HEADER FiLES and DECLARATION
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
// ALGORITHM -
//  1. if root is NULL then return emoty vector
//  2. create a stack and initially push the value of root in stack
//  3. loop while ( st is not empty )
//      4. root = st.top();
//      5. push the root-> val in ans vector
//      6. check for root->right if it is not null then push it in stack
//      7. check for root->left if it is not null then push it in stack
//  8. return ans;

// Function for Iterative Preorder Traversal
vector<int> IterativePreorder(TreeNode *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    stack<TreeNode *> st;

    st.push(root);

    while (!st.empty())
    {
        root = st.top();
        st.pop();
        ans.push_back(root->val);

        if (root->right != NULL)
            st.push(root->right);
        if (root->left != NULL)
            st.push(root->left);
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

    vector<int> ans;
    ans = IterativePreorder(root);

    // Printing ans
    for (auto n : ans)
    {
        cout << n << " ";
    }

    return 0;
}
