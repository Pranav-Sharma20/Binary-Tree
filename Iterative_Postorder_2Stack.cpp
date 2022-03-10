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

vector<int> IterativePostorder(TreeNode * root)
{
    vector<int> ans;
    if(root == NULL) return ans;

    stack<TreeNode *> st1, st2;
    st1.push(root);

    while(!st1.empty())
    {
        root = st1.top();
        st1.pop();
        st2.push(root);
        if(root->left != NULL) 
        {
            st1.push(root->left);
        }
        if(root->right != NULL)
        {
            st1.push(root->right);
        }
    }
    
    while(!st2.empty()) {
        ans.push_back(st2.top()->val);
        st2.pop();
    }
    return ans;
}


int main() {
    
    TreeNode * root = newNode(3);
    root -> left = newNode(9);
    root -> right = newNode(20);
    root -> right -> left = newNode(15);
    root -> right -> right = newNode(7);

    vector<int> ans;
    ans = IterativePostorder(root);

    // Printing ans
    for (auto n : ans)
    {
        cout << n << " ";
    }

    return 0;
}