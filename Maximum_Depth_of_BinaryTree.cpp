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

int MaxHeight(TreeNode * root)
{
    if(root == NULL) return 0;

    int lh = MaxHeight(root->left);
    int rh = MaxHeight(root->right);
    
    return 1+max(lh, rh);
}

int main() {
    
    TreeNode * root = newNode(3);
    root -> left = newNode(9);
    root -> right = newNode(20);
    root -> right -> left = newNode(15);
    root -> right -> right = newNode(7);

    int maxheight;
    maxheight = MaxHeight(root);

    cout << "Maximum Height Is : "<< maxheight ;

    return 0;
}