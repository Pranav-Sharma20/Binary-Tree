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

// Similar logic to the maximum height function
int helper(TreeNode * root , int & maxi)
{
    if(root == NULL) return 0;

    // Here we took max to avoid the case of negative number
    /*
                10
               /  \
             -4   -5
        In the above example we must not any one of the path coz they can't
        contribute anyhow in maximizing the path sum. So we take 0 instead.
    */
    int left = max(0, helper(root->left, maxi));
    int right = max(0, helper(root-> right, maxi));

    maxi = max(maxi, root->val + left + right);

    return root -> val + max(left, right);
}

// Pass maxi as an attribute it will contain the max path in the end
int maxPathSum(TreeNode* root){
    int maxi = INT_MIN;
    helper(root, maxi);
    return maxi;
}

int main() {
    
    TreeNode * root = newNode(3);
    root -> left = newNode(9);
    root -> right = newNode(20);
    root -> right -> left = newNode(15);
    root -> right -> right = newNode(7);

    int Maximum_Path_sum = maxPathSum(root);
    cout << "Maximum Path Sum is -> " << Maximum_Path_sum << "\n";

    return 0;
}