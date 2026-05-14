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
    bool isLeaf(TreeNode* node){
        return (node->left == nullptr && node->right == nullptr);
    }
    void addLeftBoundary(TreeNode* root, vector<int> &res){
        TreeNode* curr = root->left;
        while(curr){
            if(!isLeaf(curr))   res.emplace_back(curr->val);
            if(curr->left)  curr = curr->left;
            else    curr = curr->right;
        }
    }    
    void addLeaves(TreeNode*root, vector<int> &res){
        if(isLeaf(root)){
            res.emplace_back(root->val);
            return;
        }
        if(root->left)  addLeaves(root->left, res);
        if(root->right)  addLeaves(root->right, res);
    }
    void addRightBoundary(TreeNode* root, vector<int> &res){
        TreeNode* curr = root->right;
        vector<int> temp;
        while(curr){
            if(!isLeaf(curr))   temp.emplace_back(curr->val);
            if(curr->right)     curr = curr->right;
            else    curr = curr->left;
        }
        for(int i=temp.size()-1; i>=0; i--){
            res.emplace_back(temp[i]);
        }
    }
    vector<int> printBoundary(TreeNode* root){
        vector<int> res;
        if(!root) return res;
        if(!isLeaf(root))   res.emplace_back(root->val);
        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);
        return res;
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
    cout << "Enter tree nodes in level order (-1 for NULL): ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    Solution sol;
    TreeNode* root = sol.buildTree(arr);
    vector<int> boundary = sol.printBoundary(root);
    cout << "Boundary Traversal: ";
    for(const auto val : boundary){
        cout << val << " ";
    }
    cout << endl;
    return 0;
}