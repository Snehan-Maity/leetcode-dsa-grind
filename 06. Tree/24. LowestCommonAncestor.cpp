#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution{
public:
    // Function to find node by value
    TreeNode* findNode(TreeNode* root, int val){
        if(!root) return NULL;

        if(root->val == val)
            return root;

        TreeNode* left = findNode(root->left, val);
        if(left) return left;

        return findNode(root->right, val);
    }

    TreeNode* lca(TreeNode* root, TreeNode*p, TreeNode*q){
        if(!root || root==p || root==q)     return root;
        TreeNode* left = lca(root->left, p, q);
        TreeNode* right = lca(root->right, p, q);
        if(!left)   return right;
        else if(!right)   return left;
        else    return root;
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

int main(){
    int n;
    cout << "Enter number of nodes : ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the tree nodes in level order (-1 for NULL): ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }


    Solution sol;
    TreeNode* root = sol.buildTree(arr);
    
    int x, y;
    cout << "Enter the two node values to find LCA : ";
    cin >> x >> y;

    TreeNode* p = sol.findNode(root, x);
    TreeNode* q = sol.findNode(root, y);

    if(!p || !q){
        cout << "One or both nodes not found!" << endl;
        return 0;
    }

    TreeNode* result = sol.lca(root, p, q);

    if(result)  cout << "Lowest Common Ancestor : " << result->val << endl;
    else    cout << "Lowest Common Ancestor not found!" << endl;
    return 0;
}