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
// T.C. : O(Height)
// S.C. : O(1)
public:
    TreeNode* findLastRight(TreeNode* node){
        if(!node->right)    return node;
        return findLastRight(node->right);
    }

    TreeNode* helper(TreeNode* root){
        if(!root->left)     return root->right;
        else if(!root->right)   return root->left;
        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findLastRight(root->left);
        lastRight->right = rightChild;
        return root->left;
    }

    TreeNode* deleteNodeInBST(TreeNode* root, int key){
        if(!root)   return new TreeNode();
        if(root->val == key)    return helper(root);
        TreeNode* dummy = root;
        while(root){
            if(root->val > key){
                if(root->left && root->left->val == key){
                    root->left = helper(root->left);
                    break;
                }
                else    root = root->left;
            }
            else{
                if(root->right && root->right->val == key){
                    root->right = helper(root->right);
                    break;
                }
                else    root = root->right;
            }
        }   
        return dummy;
    }

    void displayTreeInLevelOrder(TreeNode* root){
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
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the values strictly in BST form (-1 for NULL): ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    int x;
    cout << "Enter the value you want to delete in the tree : ";
    cin >> x;
    
    Solution sol;
    TreeNode* root = sol.buildTree(arr);
    TreeNode* newTree = sol.deleteNodeInBST(root, x);

    cout << "After deleting the node, the tree in Level Order Traversal : ";
    sol.displayTreeInLevelOrder(newTree);
    return 0;
}
