#include <iostream>
#include <set>
using namespace std;

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
    set<int> duplicates;  // To store duplicates

    TreeNode* insert(TreeNode* node, int val, set<int>& seen) {
        if (node == nullptr) {
            return new TreeNode(val);
        }

        if (val == node->data) {
            duplicates.insert(val); // found a duplicate
        } else if (val < node->data) {
            node->left = insert(node->left, val, seen);
        } else {
            node->right = insert(node->right, val, seen);
        }
        return node;
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(int val, set<int>& seen) {
        root = insert(root, val, seen);
    }

    void findDuplicates(int arr[], int n) {
        set<int> seen;
        for (int i = 0; i < n; ++i) {
            if (seen.count(arr[i])) {
                duplicates.insert(arr[i]);
            } else {
                seen.insert(arr[i]);
                insert(arr[i], seen);
            }
        }

        // Display duplicates
        if (duplicates.empty()) {
            cout << "No duplicate elements found.\n";
        } else {
            cout << "Duplicate elements: ";
            for (int val : duplicates) {
                cout << val << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    BST tree;
    tree.findDuplicates(arr, n);

    return 0;
}
