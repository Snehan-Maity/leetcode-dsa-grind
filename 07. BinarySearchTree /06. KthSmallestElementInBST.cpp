#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode() : val(-1), left(nullptr), right(nullptr) {}
};
class Solution{
// T.C. : O(N)
// S.C. : O(1)
private:
    int inOrder(TreeNode* root, int &k){
        if(root){
            inOrder(root->left, k);
            if(--k == 0)    return root->val;
            inOrder(root->right, k);
        }
    }

public:
    int kthSmallest(TreeNode* root, int k){
        return inOrder(root, k);
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
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the values strictly in BST form (-1 for NULL): ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    int k;
    cout << "Enter the value of k : ";
    cin >> k;
    
    Solution sol;
    TreeNode* root = sol.buildTree(arr);
    cout << k << "th Smallest Element in the tree is : " << sol.kthSmallest(root, k);
    return 0;
}
