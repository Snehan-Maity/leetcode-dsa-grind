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
    TreeNode* buildTree(vector<int> &postOrder, int postSt, int postEnd, vector<int> &inOrder, int inSt, int inEnd, unordered_map<int, int> &mpp){
        if(postSt > postEnd || inSt > inEnd)  return NULL;
        TreeNode* root = new TreeNode(postOrder[postEnd]);

        int rootInd = mpp[postOrder[postEnd]];
        int numsLeft = rootInd-inSt;
        
        root->left = buildTree(postOrder, postSt, postSt+numsLeft-1, inOrder, inSt, rootInd-1, mpp);
        root->right = buildTree(postOrder, postSt+numsLeft, postEnd-1, inOrder, rootInd+1, inEnd, mpp);
        return root;
    }
public:
    TreeNode* createTree(vector<int> &postOrder, vector<int> &inOrder){
        unordered_map<int, int> mpp;
        for(int i=0; i<inOrder.size(); i++){
            mpp[inOrder[i]] = i;
        }
        return buildTree(postOrder, 0, postOrder.size()-1, inOrder, 0, inOrder.size()-1, mpp);
    }
    void displayTreeInLevelOrder(TreeNode* root){
        if(root == nullptr){
            cout << "Tree is empty\n";
            return;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            cout << node->val << " ";
            if(node->left)    q.push(node->left);
            if(node->right)    q.push(node->right);
        }
        cout << endl;
    }
};

int main(){
    int n;
    cout << "Enter number of nodes : ";
    cin >> n;

    vector<int> postOrder(n);
    cout << "Enter the tree nodes in Post-order traversal : ";
    for(int i=0; i<n; i++){
        cin >> postOrder[i];
    }
    vector<int> inOrder(n);
    cout << "Enter the tree nodes in In-order traversal : ";
    for(int i=0; i<n; i++){
        cin >> inOrder[i];
    }

    Solution sol;
    TreeNode* root = sol.createTree(postOrder, inOrder);
    cout << "The tree built from InOrder & PostOrder in Level-Order Traversal: ";
    sol.displayTreeInLevelOrder(root);
    return 0;
}
