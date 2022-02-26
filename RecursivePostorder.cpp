#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
};

void helper(TreeNode* root, vector<int>& ans){
    helper(root->left, ans);
    helper(root->left, ans);
    ans.push_back(root->val);
}
vector<int> postorder(TreeNode* root)
{
    vector<int> ans;
    helper(root, ans);
    return ans;
}