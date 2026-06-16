#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution{
// T.C. : O(Height) = O(log2 n)
// S.C. : O(1)
public:
    TreeNode* insertNodeInBST(TreeNode* root, int key){
        if(!root)   return new TreeNode(key);
        TreeNode* curr = root;
        while(true){
            if(curr->val <= key){
                if(curr->right)     curr=curr->right;
                else{
                    curr->right = new TreeNode(key);
                    break;
                }
            }
            else{
                if(curr->left)  curr=curr->left;
                else{
                    curr->left = new TreeNode(key);
                    break;
                }
            }
        }
        return root;
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
    cout << "Enter the value you want to insert in the tree : ";
    cin >> x;
    
    Solution sol;
    TreeNode* root = sol.buildTree(arr);
    TreeNode* newTree = sol.insertNodeInBST(root, x);

    cout << "After inserting the node, the tree in Level Order Traversal : ";
    sol.displayTreeInLevelOrder(newTree);
    return 0;
}
