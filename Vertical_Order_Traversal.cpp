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

vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode *, pair<int, int>>> todo;
        
        todo.push({root,{0,0}});
        
        while(!todo.empty()){
            auto p = todo.front();
            todo.pop();
            TreeNode *node = p.first;
            int x = p.second.first;
            int y = p.second.second;
            nodes[x][y].insert(node->val);
            
            if(node -> left != NULL)
            {
                todo.push({node -> left, {x - 1 , y + 1}});
            }
            if(node -> right != NULL)
            {
                todo.push({node -> right, {x + 1 , y + 1}});
            }
        }
        vector<vector<int>> ans;
        
        for(auto p : nodes)
        {
            vector<int> col;
            for(auto q : p.second)
            {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
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

    vector<vector<int>> ans;

    ans = verticalTraversal(root);

    for (auto n : ans)
    {
        cout << '[' ;
        for(auto s : n)
        {
            cout << s << " ";
        }
        cout << ']';
    }

    return 0;
}