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

vector<int> Top_View (TreeNode * root)
{
    queue<pair<TreeNode* , int>> todo;
    map<int, int> nodes;

    todo.push({root, 0});

    while(!todo.empty()){
        auto p = todo.front();
        todo.pop();

        int x = p.second;

        if(nodes.find(x) == nodes.end()){
            nodes[x] = p.first -> val;
        }

        if(p.first -> left)
        {
            todo.push({p.first -> left, x-1});
        }

        if(p.first -> right)
        {
            todo.push({p.first -> right, x+1});
        }
    }
    vector<int> ans;

    for(auto p : nodes)
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
    ans = Top_View(root);

    for(auto o : ans)
    {
        cout << o << " " ;
    }

    return 0;
}