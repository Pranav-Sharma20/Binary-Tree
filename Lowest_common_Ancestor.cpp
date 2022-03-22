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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    if(root == NULL || root == p || root == q){
        return root;
    }
    
    TreeNode * left = lowestCommonAncestor(root -> left , p, q);
    TreeNode * right = lowestCommonAncestor(root ->right, p, q);
    
    if(left == NULL){ // If Left one is returning null
        return right;
    }
    else if(right == NULL){ // If right one is returning NUll
        return left;
    }
    else { // if both of them are under this node that means non of them are null
        return root;
    }
}


int main() {
    TreeNode * root = newNode(3);
    root -> left = newNode(9);
    root -> right = newNode(20);
    root -> right -> left = newNode(15);
    root -> right -> right = newNode(7);

    cout << "lowest Common Ancestor : " << lowestCommonAncestor(root, root->right->right, root -> right->left)->val;
    return 0;
}