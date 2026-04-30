#include<bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* buildTree() {
        int val;
        cin >> val;
        if (val == -1) return NULL;     // No child
        TreeNode* root = new TreeNode(val);
        root->left = buildTree();
        root->right = buildTree();
        return root;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        bool flag = true;
        while(!q.empty()){
            int sz = q.size();
            vector<int>row(sz);
            for(int i=0; i<sz; i++){
                TreeNode* temp = q.front();
                q.pop();
                int ind = flag? i : sz-1-i;
                row[ind] = temp->val;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            ans.push_back(row);
            flag = !flag;
        }
        return ans;
    }
};
int main() {
    Solution obj;
    cout << "Enter tree (preorder with -1 for NULL): \n";
    TreeNode* root = obj.buildTree();
    vector<vector<int>> ans = obj.zigzagLevelOrder(root);
    cout << "Zigzag Level Order: [";
    for (int i = 0; i < ans.size(); i++) {
        cout << "[";
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j];
            if (j != ans[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i != ans.size() - 1) cout << ",";
    }
    cout << "]";
    return 0;
}