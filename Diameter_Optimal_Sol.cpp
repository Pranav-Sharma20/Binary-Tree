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

int Height(TreeNode* root, int &Max_Diameter)
{
    if(root == NULL) return 0;

    int lh = Height(root->left,Max_Diameter);
    int rh = Height(root->right,Max_Diameter);

    Max_Diameter = max(Max_Diameter , lh+rh);

    return 1+ max(lh,rh);
}

int diameterOfBinaryTree(TreeNode* root){
    int Diameter=0;
    Height(root, Diameter);
    return Diameter;
}


int main() {
    int i, j;
    TreeNode * root = newNode(3);
    root -> left = newNode(9);
    root -> right = newNode(20);
    root -> right -> left = newNode(15);
    root -> right -> right = newNode(7);

    int Diameter = diameterOfBinaryTree(root);

    cout << " Diameter -> " <<  Diameter << "\n";

    return 0;
}