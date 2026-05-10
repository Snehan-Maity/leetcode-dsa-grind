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
    bool isIdenticalTree(TreeNode* p, TreeNode* q){
        if(!p || !q)    return p==q;
        return (p->val==q->val) && isIdenticalTree(p->left,q->left) && isIdenticalTree(p->right, q->right);
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
    cout << "Enter number of nodes for both the trees : ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter values for 1st tree (-1 for NULL): ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int> arr2(n);
    cout << "Enter values for 2nd tree (-1 for NULL): ";
    for(int i = 0; i < n; i++){
        cin >> arr2[i];
    }

    Solution sol;
    TreeNode* p = sol.buildTree(arr);
    TreeNode* q = sol.buildTree(arr2);

    if(sol.isIdenticalTree(p,q))    cout << "The 2 trees are Identical";
    else cout << "The 2 trees are not Identical";
    return 0;
}