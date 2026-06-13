#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution{
// T.C. : O(Height)
// S.C. : O(1)
public:
    TreeNode* searchBST(TreeNode* root, int x){
        while(root && root->val != x){
            root = (x<root->val)? root->left : root->right;
        }
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
    cout << "Enter values (-1 for NULL): ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    int x;
    cout << "Enter value to search: ";
    cin >> x;
    
    Solution sol;
    TreeNode* root = sol.buildTree(arr);
    TreeNode* ans = sol.searchBST(root, x);

    if(ans)     cout << "Node found with value: " << ans->val << endl;
    else     cout << "Node not found" << endl;

    return 0;
}
