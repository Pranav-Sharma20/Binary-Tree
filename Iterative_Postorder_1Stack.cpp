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

vector<int> IterativePostorder (TreeNode * root)
{
    vector<int> ans;
    if(root == NULL) return ans;

    stack<TreeNode *> st;

    TreeNode* curr = root;
    while(curr != NULL || !st.empty())
    {
        if(curr != NULL)
        {
            st.push(curr);
            curr = curr -> left;
        }
        else{
            TreeNode *temp = st.top()-> right;
            if(temp == NULL)
            {
                temp = st.top();
                st.pop();
                ans.push_back(temp->val);
                while(!st.empty() && temp == st.top()->right) 
                {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);
                }
            }
            else
            {
                curr = temp;
            }
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
    ans = IterativePostorder(root);

    // Printing ans
    for (auto n : ans)
    {
        cout << n << " ";
    }

    return 0;
}