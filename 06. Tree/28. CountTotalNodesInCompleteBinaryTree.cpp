#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution{
// T.C = O((log2n)^2)
private:
    int findLeftHeight(TreeNode* node){
        int h=0;
        while(node){
            h++;
            node = node->left;
        }
        return h;
    }
    int findRightHeight(TreeNode* node){
        int h=0;
        while(node){
            h++;
            node = node->right;
        }
        return h;
    }

public:
    int countNodes(TreeNode* root){
        if(!root)   return 0;
        int lh=findLeftHeight(root);    // O(log2n)
        int rh=findRightHeight(root);   // O(log2n)
        if(lh == rh)    return (1<<lh)-1; // 2^lh - 1
        return 1+ countNodes(root->left)+countNodes(root->right);   // O(log2n)
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
    
    cout << "Total number of nodes in the complete binary tree is : " <<  sol.countNodes(root) << endl;
    return 0;
}