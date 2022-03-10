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

// Time Complexity -> O(N^2) {For example if we have a degenerate tree}
// Initially we declare the Max_Diameter a Global variable 
int Max_Diameter = INT_MIN;
int diameterOfBinaryTree(TreeNode* root) {
    if(root == NULL) return 0;

    int lh = MaxHeight(root -> left);
    int rh = MaxHeight(root -> right);

    Max_Diameter = max(Max_Diameter, lh+rh);

    diameterOfBinaryTree(root -> left);
    diameterOfBinaryTree(root -> left);

    return Max_Diameter;
} 


int main() {
    
    TreeNode * root = newNode(3);
    root -> left = newNode(9);
    root -> right = newNode(20);
    root -> right -> left = newNode(15);
    root -> right -> right = newNode(7);
    
    int Diameter = diameterOfBinaryTree(root);

    cout << "Diameter of Binary Tree is -> " << Diameter << "\n";

    return 0;
}