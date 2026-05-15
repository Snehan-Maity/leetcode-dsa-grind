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
    vector<vector<int>> verticalOrderTraversal(TreeNode* root){
        if(!root)   return {{}};
        queue<pair<TreeNode*, pair<int, int>>> q;
        map<int, map<int, multiset<int>>> mpp;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int x = it.second.first;
            int y = it.second.second;
            mpp[x][y].insert(it.first->val);
            if(it.first->left)  q.push({it.first->left, {x-1, y+1}});
            if(it.first->right)  q.push({it.first->right, {x+1, y+1}});
        }
        vector<vector<int>> ans;
        for(const auto &it: mpp){
            vector<int> verticals;
            for(const auto &it2: it.second){
                verticals.insert(verticals.end(), it2.second.begin(), it2.second.end());
            }
            ans.emplace_back(verticals);
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
    vector<vector<int>> result = sol.verticalOrderTraversal(root);
    cout << "Vertical Order Traversal:\n";
    for(const auto &it : result){
        for(int i=0; i<it.size(); i++){
            cout << it[i] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}