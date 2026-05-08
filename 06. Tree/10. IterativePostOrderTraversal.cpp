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
    void print(vector<int> &arr){
        for(const auto &it: arr)    cout << it << " ";
    }
    vector<int> postOrderTraversal(TreeNode* root){
        vector<int> post;
        if(!root)   return post;
        stack<TreeNode*> st1, st2;
        st1.push(root);
        while(!st1.empty()){
            root = st1.top();
            st1.pop();
            st2.push(root);
            if(root->left)  st1.push(root->left);
            if(root->right)  st1.push(root->right);
        }
        while(!st2.empty()){
            post.emplace_back(st2.top()->val);
            st2.pop();
        }
        return post;
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
    cout << "Enter values (-1 for NULL): ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    Solution sol;
    TreeNode* root = sol.buildTree(arr);
    vector<int> result = sol.postOrderTraversal(root);

    cout << "\nPostOrder Traversal : ";
    sol.print(result);
    cout << endl;
    return 0;
}