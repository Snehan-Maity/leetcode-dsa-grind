#include <bits/stdc++.h>
using namespace std;

// TreeNode structure
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void inOrder(TreeNode* root, vector<int> &in){
        if(!root)    return;
        if(root->left)     inOrder(root->left);
        in.emplace_back(root->val);
        if(root->right)     inOrder(root->right);
        return;
    }
};

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

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter values (-1 for NULL): ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    TreeNode* root = buildTree(arr);

    Solution sol;
    vector<int> in;
    sol.inOrder(root, in);

    cout << "Inorder Traversal: ";
    for(const int &it : in){
        cout << it << " ";
    }
    cout << endl;

    return 0;
}
