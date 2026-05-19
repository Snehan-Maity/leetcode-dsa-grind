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
    bool isSymmetric(TreeNode* p, TreeNode* q){
        if(!p || !q)    return p==q;
        return ((p->val == q->val) && isSymmetric(p->left, q->right) && isSymmetric(p->right, q->left));
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
    cout << "Enter the 1st tree nodes in level order (-1 for NULL): ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int> arr2(n);
    cout << "Enter the 2nd tree nodes in level order (-1 for NULL): ";
    for(int i = 0; i < n; i++){
        cin >> arr2[i];
    }
    Solution sol;
    TreeNode* p = sol.buildTree(arr);
    TreeNode* q = sol.buildTree(arr2);
    if(sol.isSymmetric(p, q))   cout << "The 2 trees are Symmetrical";
    else    cout << "The 2 trees are not Symmetrical";
    return 0;
}