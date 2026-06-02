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
    TreeNode* makeParentsAndReturnTargetNode(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track, int target){
        queue<TreeNode*> q;
        TreeNode* targetNode;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr->val == target)     targetNode = curr;
            if(curr->left){
                parent_track[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right){
                parent_track[curr->right] = curr;
                q.push(curr->right);
            }
        }
        return targetNode;
    }

    int findMaxTime(unordered_map<TreeNode*, TreeNode*> &parent_track, TreeNode* target){
        if(!target)     return 0;
        queue<TreeNode*> q;
        q.push(target);
        unordered_map<TreeNode*, int> vis;
        vis[target]=1;
        int maxi=0;
        while(!q.empty()){
            int sz = q.size(), flag=0;
            for(int i=0; i<sz; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !vis[node->left]){
                    flag=1;
                    q.push(node->left);
                    vis[node->left]=1;
                }
                if(node->right && !vis[node->right]){
                    flag=1;
                    q.push(node->right);
                    vis[node->right]=1;
                }
                if(parent_track.count(node) && !vis[parent_track[node]]){
                    flag=1;
                    q.push(parent_track[node]);
                    vis[parent_track[node]]=1;
                }
            }
            if(flag)  maxi++;
        }
        return maxi;        
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
    cout << "Enter the tree nodes in level order (-1 for NULL): ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int targetVal;
    cout << "Enter target node value from where you want to burn the tree: ";
    cin >> targetVal;

    Solution sol;
    TreeNode* root = sol.buildTree(arr);
    
    unordered_map<TreeNode*, TreeNode*> parents;
    TreeNode* targetNode = sol.makeParentsAndReturnTargetNode(root, parents, targetVal);
    cout << "Minimum time to burn the tree from node " << targetVal << " is: " << sol.findMaxTime(parents, targetNode);
    return 0;
}
