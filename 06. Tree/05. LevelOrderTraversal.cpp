#include <bits/stdc++.h>
using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root == NULL)    return ans;
        q.push(root);
        while(!q.empty()){
            vector<int> level;
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                level.emplace_back(node->val);
                q.pop();
                if(node->left != NULL)    q.push(node->left);
                if(node->right != NULL)    q.push(node->right);
            }
            ans.emplace_back(level);
        }
        return ans;
    }
};

// Function to build tree from level order
TreeNode* buildTree(vector<int>& arr) {
    if(arr.empty() || arr[0] == -1) return NULL;

    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while(!q.empty() && i < arr.size()){
        TreeNode* curr = q.front();
        q.pop();

        // Left child
        if(i < arr.size() && arr[i] != -1){
            curr->left = new TreeNode(arr[i]);
            q.push(curr->left);
        }
        i++;

        // Right child
        if(i < arr.size() && arr[i] != -1){
            curr->right = new TreeNode(arr[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    TreeNode* root = buildTree(arr);

    Solution sol;
    vector<vector<int>> result = sol.levelOrder(root);

    // Print level order result
    for(auto &level : result){
        for(int val : level){
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}