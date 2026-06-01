#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution{
private:
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
public:
    vector<int> distanceK(TreeNode* root, int target, int k){
        unordered_map<TreeNode*, TreeNode*> parent_track;
        TreeNode* targetNode = makeParentsAndReturnTargetNode(root, parent_track, target);
        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;
        q.push(targetNode);
        vis[targetNode]=true;
        int curr_level=0;
        while(!q.empty()){
            int sz = q.size();
            if(curr_level++ == k)   break;
            for(int i=0; i<sz; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left && !vis[curr->left]){
                    q.push(curr->left);
                    vis[curr->left]=true;
                }
                if(curr->right && !vis[curr->right]){
                    q.push(curr->right);
                    vis[curr->right]=true;
                }
                if(parent_track.count(curr) && !vis[parent_track[curr]]){
                    q.push(parent_track[curr]);
                    vis[parent_track[curr]]=true;
                }
            }
        }
        vector<int> res;
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            res.push_back(curr->val);
        }
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
    cout << "Enter the tree nodes in level order (-1 for NULL): ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int targetVal;
    cout << "Enter target node value: ";
    cin >> targetVal;

    int k;
    cout << "Enter the distance k: ";
    cin >> k;

    Solution sol;
    TreeNode* root = sol.buildTree(arr);
    
    vector<int> ans = sol.distanceK(root, targetVal, k);
    cout << "Nodes at distance " << k << " from target " << targetVal << ": ";
    for(const int &x : ans) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
