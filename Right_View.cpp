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

void RightView(TreeNode *root , int level, vector<int>& ans)
{
    if(root == NULL) return;

    if(level == ans.size()) ans.push_back(root-> val);

    RightView(root -> right, level+1, ans);
    RightView(root -> left, level+1, ans);

}

int main() {
    int i, j;
    TreeNode * root = newNode(3);
    root -> left = newNode(9);
    root -> right = newNode(20);
    root -> right -> left = newNode(15);
    root -> right -> right = newNode(7);

    vector<int> ans;
    RightView(root, 0, ans);

    for(auto i : ans){
        cout << i << " ";
    }
    return 0;
}