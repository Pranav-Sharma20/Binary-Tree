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

vector<vector<int>> AllTraversal(TreeNode * root)
{
    vector<vector<int>> ans;
    vector<int> pre, in, post;
    if(root == NULL) return ans;

    stack<pair<TreeNode*, int>> st;
    st.push({root,1});

    while(!st.empty())
    {
        auto it = st.top();
        st.pop();


        // This is for preorder
        // push the pair again in the stack by incrementing second from 1 to 2
        // and insert the left subtree in it
        if(it.second == 1){
            pre.push_back(it.first-> val);
            it.second++;
            st.push(it);

            if(it.first-> left != NULL)
            {
                st.push({it.first -> left,1});
            }
        }

        // This is for inorder 
        // push the pair again in the stack by incrementing second from 2 to 3
        // and insert the right subtree in it
        else if(it.second == 2){
            in.push_back(it.first->val);
            it.second++;
            st.push(it);

            if(it.first -> right != NULL)
            {
                st.push({it.first-> right,1});
            }
        }

        // This is for the postorder
        // Don't push anything just store the values only
        else{
            post.push_back(it.first-> val);
        }
    }
    ans.push_back(pre);
    ans.push_back(in);
    ans.push_back(post);

    return ans;
}


int main() {
    int i, j;
    TreeNode * root = newNode(3);
    root -> left = newNode(9);
    root -> right = newNode(20);
    root -> right -> left = newNode(15);
    root -> right -> right = newNode(7);

    vector<vector<int>> ans;
    ans = AllTraversal(root);

    // Printing ans
    for (auto n : ans)
    {
        for(auto s : n)
        {
            cout << s << " ";
        }
        cout << "\n";
    }
    
    return 0;
}