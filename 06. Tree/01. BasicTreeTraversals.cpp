#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// 🔹 Organized Input using while loop
Node* createTree() {
    int val;
    cout << "Enter root value: ";
    cin >> val;

    if (val == -1) return nullptr;

    Node* root = new Node(val);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        int leftVal, rightVal;

        cout << "Enter left of " << curr->data << " (-1 for NULL): ";
        cin >> leftVal;
        if (leftVal != -1) {
            curr->left = new Node(leftVal);
            q.push(curr->left);
        }

        cout << "Enter right of " << curr->data << " (-1 for NULL): ";
        cin >> rightVal;
        if (rightVal != -1) {
            curr->right = new Node(rightVal);
            q.push(curr->right);
        }
    }

    return root;
}

class Solution {
public:
    vector<int> pre, in, post;

    void preorder(Node* root) {
        if (!root) return;
        pre.push_back(root->data);
        preorder(root->left);
        preorder(root->right);
    }

    void inorder(Node* root) {
        if (!root) return;
        inorder(root->left);
        in.push_back(root->data);
        inorder(root->right);
    }

    void postorder(Node* root) {
        if (!root) return;
        postorder(root->left);
        postorder(root->right);
        post.push_back(root->data);
    }
};

int main() {
    Node* root = createTree();

    Solution sol;
    sol.preorder(root);
    sol.inorder(root);
    sol.postorder(root);

    cout << "\nPreorder: ";
    for (int x : sol.pre) cout << x << " ";

    cout << "\nInorder: ";
    for (int x : sol.in) cout << x << " ";

    cout << "\nPostorder: ";
    for (int x : sol.post) cout << x << " ";

    return 0;
}