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
// S.C. : O(1) for iterative & O(n) for recursive

public:
    TreeNode* lcaBST(TreeNode* root, int p, int q){
        if(!root)   return NULL;
        if(root->val < p && root->val < q)    return lcaBST(root->right, p, q);
        if(root->val > p && root->val > q)    return lcaBST(root->left, p, q);
        return root;
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

    int a,b;
    cout << "Enter the two values among which you want to find Lowest Common Ancestor : ";
    cin >> a >> b;
    
    Solution sol;
    TreeNode* root = sol.buildTree(arr);

    TreeNode* ans = sol.lcaBST(root, a, b);
    cout << "The Lowest Common Ancestor of " << a << " and " << b << " is : " << ans->val;
    return 0;
}
