#include <iostream>
using namespace std;

// BST Node definition
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = right = nullptr;
    }
};

class BST {
private:
    TreeNode* root;

    // Recursive insert
    TreeNode* insert(TreeNode* node, int val) {
        if (node == nullptr)
            return new TreeNode(val);

        if (val < node->data)
            node->left = insert(node->left, val);
        else
            node->right = insert(node->right, val);

        return node;
    }

    // In-order traversal to print sorted order
    void inorder(TreeNode* node) {
        if (node == nullptr)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(int val) {
        root = insert(root, val);
    }

    void sortAndDisplay() {
        cout << "Sorted list: ";
        inorder(root);
        cout << endl;
    }
};

int main() {
    BST tree;
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int val;
    cout << "Enter the numbers:\n";
    for (int i = 0; i < n; ++i) {
        cin >> val;
        tree.insert(val);
    }

    tree.sortAndDisplay();

    return 0;
}
