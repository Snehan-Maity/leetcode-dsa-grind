#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode() : val(-1), left(nullptr), right(nullptr) {}
};
class Solution{
// T.C. : O(N)
// S.C. : O(Height)

private:
    TreeNode* buildBST(vector<int> &pre, int &i, int bound){
        if(i == pre.size() || pre[i]>bound)     return NULL;
        TreeNode* root = new TreeNode(pre[i++]);
        root->left = buildBST(pre, i, root->val);     
        root->right = buildBST(pre, i, bound);
        return root;
    }
public:
    TreeNode* bstFromPreOrder(vector<int> &pre){
        int i=0;
        return buildBST(pre, i, INT_MAX);
    }

    // To display the BST built
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
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> preOrder(n);
    cout << "Enter the values in PreOrder Traversal : ";
    for(int i = 0; i < n; i++){
        cin >> preOrder[i];
    }
    
    Solution sol;
    TreeNode* bst = sol.bstFromPreOrder(preOrder);
    if(bst)     cout << "BST in Level Order Traversal : ";
    sol.displayTreeInLevelOrder(bst);
    return 0;
}
