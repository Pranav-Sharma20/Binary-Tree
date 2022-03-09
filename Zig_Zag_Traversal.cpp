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

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        bool flag = false;
        while(!q.empty()){
            // Simple Level order trversal just added flag to push 
            // the values either from the front or back
            flag = !flag;
            
            int size = q.size();
            vector<int> temp(size);
            for(int i =0; i<size; i++)
            {
                // Checking the flag here
                int index = flag ? i: (size-1-i);
                
                TreeNode * curr = q.front();
                q.pop();
                
                if(curr -> left != NULL) q.push(curr -> left);
                if(curr -> right != NULL) q.push(curr -> right);
                
                temp[index] = curr-> val;
            }
            ans.push_back(temp);
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

    vector<vector<int>> ans = zigzagLevelOrder(root);

    for(auto i: ans)
    {
        cout << '[';
        for(auto j : i){
            cout << " "<< j << " " ;
        }
        cout << ']';
    }

    return 0;
}