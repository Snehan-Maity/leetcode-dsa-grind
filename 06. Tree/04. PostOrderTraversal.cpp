#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr)  {}
};
class Solution{
private:
    void postOrder(TreeNode* node, vector<int> &ans){
        if(!node)   return;
        postOrder(node->left, ans);
        postOrder(node->right, ans);
        ans.emplace_back(node->val);
        return;
    }
public:
    vector<int> postOrderTraversal(TreeNode* root){
        vector<int> ans;
        postOrder(root, ans);
        return ans;
    }
    
    // Function to build tree from level order
    TreeNode* buildTree(vector<int>& arr) {
        if(arr.size() == 0 || arr[0] == -1) return NULL;

        TreeNode* root = new TreeNode(arr[0]);
        queue<TreeNode*> q;
        q.push(root);

        int i = 1;
        while(!q.empty() && i < arr.size()){
            TreeNode* curr = q.front();
            q.pop();

            // Left child
            if(arr[i] != -1){
                curr->left = new TreeNode(arr[i]);
                q.push(curr->left);
            }
            i++;

            if(i >= arr.size()) break;

            // Right child
            if(arr[i] != -1){
                curr->right = new TreeNode(arr[i]);
                q.push(curr->right);
            }
            i++;
        }
        return root;
    }
};

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter values (-1 for NULL): ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    Solution sol;
    TreeNode* root = sol.buildTree(arr);
    vector<int> result = sol.postOrderTraversal(root);

    cout << "PostOrder Traversal : ";
    for(int val : result){
        cout << val << " ";
    }
    cout << endl;
    return 0;
}