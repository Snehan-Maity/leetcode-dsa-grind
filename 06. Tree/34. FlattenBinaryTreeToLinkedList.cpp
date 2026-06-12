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
    // T.C. = O(n)
    // S.C. = O(1)
    void falttenTree(TreeNode* &root){
        if(!root)   return;
        TreeNode* curr=root;
        while(curr){
            if(curr->left){
                TreeNode* prev = curr->left;
                while(prev->right)  prev=prev->right;
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }

    void displayTreeInLevelOrder(TreeNode* &root){
        if(root == nullptr){
            cout << "Tree is empty\n";
            return;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            cout << node->val << " ";
            if(node->left)    q.push(node->left);
            if(node->right)    q.push(node->right);
        }
        cout << endl;
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
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    Solution sol;
    TreeNode* root = sol.buildTree(arr);
    
    sol.falttenTree(root);
    cout << "After flattening the tree : ";
    sol.displayTreeInLevelOrder(root);
    return 0;
}
