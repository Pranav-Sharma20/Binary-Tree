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

// The same technique can be followed to find the path from root to some node and there is one question on
// Leetcode too that is you have to print all the root to leaf path of a Binary tree.

void helper(TreeNode *root , vector<string>& ans, string temp){
    if(root == NULL) return;

    if(root -> left == NULL||root -> right == NULL){
        temp += to_string(root -> val);
        ans.push_back(temp);
    }

    temp += to_string(root -> val)+"->";
    helper(root -> left, ans, temp);
    helper(root -> right, ans, temp);

}

vector<string> RootToleaf(TreeNode* root){
    vector<string> ans;
    string temp = "";
    helper(root, ans, temp);
    return ans;
}


int main() {
    TreeNode * root = newNode(3);
    root -> left = newNode(9);
    root -> right = newNode(20);
    root -> right -> left = newNode(15);
    root -> right -> right = newNode(7);

    vector<string> ans;
    ans = RootToleaf(root);

    for(auto i : ans){
        cout << i << ',';
    }
    return 0;
}