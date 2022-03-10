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

vector<int> IterativeInorder (TreeNode * root)
{
    TreeNode *node = root;
    
    vector<int> ans;
    stack<TreeNode *> st;

    while(true){
        if(node != NULL)
        {
            st.push(node);
            node = node->left;
        }
        else{
            if(st.empty()) break;
            node = st.top();
            st.pop();
            ans.push_back(node->val);
            node = node-> right;
        }
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
    ans = IterativeInorder(root);

    // Printing ans
    for (auto n : ans)
    {
        cout << n << " ";
    }

    return 0;
}