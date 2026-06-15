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
    int floorInBST(TreeNode* root, int key){
        int floor=INT_MAX;
        while(root){
            if(key == root->val){
                floor = root->val;
                return floor;
            }
            else if(key < root->val)    root=root->left;
            else{
                floor = root->val;
                root = root->right;
            }
        }
        return floor;
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
    cout << "Enter the value to find its ceil : ";
    cin >> x;
    
    Solution sol;
    TreeNode* root = sol.buildTree(arr);
    int ans = sol.floorInBST(root, x);

    cout << "Floor of " << x << " is : " << ans << endl;
    return 0;
}
