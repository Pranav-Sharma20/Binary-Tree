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
// Same logic as the top view just the difference is that we don't
// have to check any condition while inserting just insert insert in the map
// You will get it refer to notes and top view code once

vector<int> Bottom_View(TreeNode * root){
    vector<int> ans;
    if(root == NULL) return ans;

    queue<pair<TreeNode*,int>> todo;
    map<int,int> nodes;

    todo.push({root, 0});

    while(!todo.empty()){
        auto p = todo.front();
        todo.pop();
        
        int x = p.second;
        
        // the if condition that I am talking about
        nodes[x] = p.first -> val;

        if(p.first -> left)
        {
            todo.push({p.first-> left, x-1});
        }

        if(p.first -> right)
        {
            todo.push({p.first-> right, x+1});
        }
    }
    for(auto p: nodes)
    {
        ans.push_back(p.second);
    }
    return ans;
}



int main() {
    int i, j;
    TreeNode * root = newNode(3);
    root -> left = newNode(9);
    root -> right = newNode(20);
    root -> right -> left = newNode(15);
    root -> right -> right = newNode(7);

    vector<int> ans;
    ans = Bottom_View(root);

    for(auto i : ans){
        cout << i << " ";
    }
    return 0;
}