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
    TreeNode* buildTree(vector<int> &preOrder, int preSt, int preEnd, vector<int> &inOrder, int inSt, int inEnd, unordered_map<int, int> &mpp){
        if(preSt > preEnd || inSt > inEnd)  return NULL;
        TreeNode* root = new TreeNode(preOrder[preSt]);

        int rootInd = mpp[preOrder[preSt]];
        int numsLeft = rootInd-inSt;
        
        root->left = buildTree(preOrder, preSt+1, preSt+numsLeft, inOrder, inSt, rootInd-1, mpp);
        root->right = buildTree(preOrder, preSt+numsLeft+1, preEnd, inOrder, rootInd+1, inEnd, mpp);
        return root;
    }
public:
    TreeNode* createTree(vector<int> &preOrder, vector<int> &inOrder){
        unordered_map<int, int> mpp;
        for(int i=0; i<inOrder.size(); i++){
            mpp[inOrder[i]] = i;
        }
        return buildTree(preOrder, 0, preOrder.size()-1, inOrder, 0, inOrder.size()-1, mpp);
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

    vector<int> preOrder(n);
    cout << "Enter the tree nodes in Pre-order traversal : ";
    for(int i=0; i<n; i++){
        cin >> preOrder[i];
    }
    vector<int> inOrder(n);
    cout << "Enter the tree nodes in In-order traversal : ";
    for(int i=0; i<n; i++){
        cin >> inOrder[i];
    }

    Solution sol;
    TreeNode* root = sol.createTree(preOrder, inOrder);
    cout << "The tree built from InOrder & PreOrder in Level-Order Traversal: ";
    sol.displayTreeInLevelOrder(root);
    return 0;
}
