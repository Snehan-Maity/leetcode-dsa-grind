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
    // Function to change the values of the nodes based on the sum of its children's values
    void changeTree(TreeNode* root) {
        if (!root)  return ;
        int child = 0;
        if (root->left)     child += root->left->val;
        if (root->right)    child += root->right->val;
        
        // Compare the sum of children with the current node's value and update
        if (child >= root->val)     root->val = child;
        else{
            // If the sum is smaller, update the child with the current node's value
            if (root->left)     root->left->val = root->val;
            else if(root->right)    root->right->val = root->val;
        }

        // Recursively call the function on the left and right children
        changeTree(root->left);
        changeTree(root->right);

        // Calculate the total sum of the values of the left and right children, if they exist
        int tot = 0;
        if(root->left)     tot += root->left->val;
        if(root->right)     tot += root->right->val;

        // If either left or right child exists, update the current node's value with the total sum
        if (root->left or root->right)  root->val = tot;
    }
    
    // Function to print the inorder traversal of the tree
    void inorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        inorderTraversal(root->left);
        cout << root->val << " ";
        inorderTraversal(root->right);
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
    
    cout << "Binary Tree before modification: ";
    sol.inorderTraversal(root);
    cout << endl;

    sol.changeTree(root);

    cout << "Binary Tree after Children Sum Property: " ;
    sol.inorderTraversal(root);
    cout << endl;

    return 0;
}
                            