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
// T.C. : O(log n)
// S.C. : O(1)

public:
    TreeNode* inOrderPredecessor(TreeNode* root, int p){
        TreeNode* pred = NULL;
        while(root){
            if(p > root->val){
                pred = root;
                root = root->right;
            }
            else    root = root->left;
        }
        return pred;
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
    cout << "Enter the values strictly in BST in level order traversal (-1 for null) : ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    int x;
    cout << "Enter the value whose predecessor you want to find out : ";
    cin >> x;

    Solution sol;
    TreeNode* root = sol.buildTree(arr);

    TreeNode* predecessor = sol.inOrderPredecessor(root, x);

    if(predecessor)     cout << "Predecessor of " << x << " in the BST is : " << predecessor->val;
    else    cout << "No predecessor exists";
    return 0;
}
