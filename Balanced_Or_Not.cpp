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
    
    if(lh == -1 || rh == -1) return -1;
    if(abs(lh-rh) > 1) return -1;

    return 1+max(lh, rh);
}


bool Balaced_Or_Not (TreeNode * root)
{
    int a = MaxHeight(root);
    if(a == -1) return false;
    else return true;
}

int main() {
    int i, j;
    TreeNode * root = newNode(3);
    root -> left = newNode(9);
    root -> right = newNode(20);
    root -> right -> left = newNode(15);
    root -> right -> right = newNode(7);
    root -> right -> right -> right = newNode(7);

    bool ans;
    ans = Balaced_Or_Not(root);
    if(ans) cout << "BALANCED";
    else cout << "NOT BALANCED";
    return 0;
}