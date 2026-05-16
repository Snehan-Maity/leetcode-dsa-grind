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
    vector<int> topView(TreeNode* root){
        if(!root)   return {};
        queue<pair<TreeNode*, int>> q;
        map<int, int> mpp;
        q.push({root,0});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int x = it.second;
            if(mpp.find(x) == mpp.end())     mpp[x] = it.first->val;
            if(it.first->left)  q.push({it.first->left, x-1});
            if(it.first->right)  q.push({it.first->right, x+1});
        }
        vector<int> ans;
        for(const auto &it: mpp){
            ans.emplace_back(it.second);
        }
        return ans;
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
    vector<int> result = sol.topView(root);
    cout << "TopView of the Tree : ";
    for(const auto &it : result){
        cout << it << " ";
    }
    cout << endl;
    return 0;
}