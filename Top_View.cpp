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
    vector<int> ans;
    if(root == NULL) return ans;

    // Declared Queue for doing level order Traversal
    queue<pair<TreeNode* , int>> todo;

    // Declared a map to store values mapped with its x-axis coordinates
    map<int, int> nodes;

    todo.push({root, 0});

    while(!todo.empty()){
        auto p = todo.front();
        todo.pop();

        int x = p.second;

        // insert values in map only when we are visiting the node
        // for that coordinate for the first time only
        /*
                    3
                   /  \
                  4    7
                 / \
                5   6 

            see the above example when we see from the top we won't see 6 instead
            we will see 3 so we will insert 3 in the map but when again the value 6 comes
            on the same coordinate we will not insert that in our map
        */
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