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

int MaxHeight(TreeNode *root)
{
    if(!root) return 0;

    int lh = MaxHeight(root -> left);
    int rh = MaxHeight(root -> right);

    return 1 + max(lh, rh);
}


// This is a O(n^2) solution because for every subtree 
// We are checking wether it is Balanced or not
bool check(TreeNode * root)
{
    if(!root) return true;

    int Lh = MaxHeight(root->left);
    int Rh = MaxHeight(root->right);

    if(abs(Lh-Rh) > 1) return false;

    bool left = check(root -> left);
    bool right = check(root -> right);

    if(!left || !right) return false;
    
    return true;
}


int main() {
    
    TreeNode * root = newNode(3);
    root -> left = newNode(9);
    root -> right = newNode(20);
    root -> right -> left = newNode(15);
    root -> right -> right = newNode(7);

    bool ans = check(root);

    if(ans){
        cout << "Balanced";
    }
    else{
        cout << "NOT Balanced";
    }

    return 0;
}