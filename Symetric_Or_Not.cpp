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
bool isSymetricHelper(TreeNode *left, TreeNode *right){
    if(left == NULL || right == NULL) return left == right;

    if(left -> val != right -> val) return false;

    return isSymetricHelper(left -> left , right -> right) && isSymetricHelper(left -> right , right -> left);
}
bool isSymmetric(TreeNode* root){
    return root == NULL || isSymetricHelper(root -> left, root -> right);  
}

int main() {
    TreeNode * root = newNode(3);
    root -> left = newNode(9);
    root -> right = newNode(9);
    root -> left -> left = newNode(15);
    root -> left -> right = newNode(7);
    root -> right -> left = newNode(7);
    root -> right -> right = newNode(15);

    cout << isSymmetric(root);
    return 0;
}