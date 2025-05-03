#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    bool lthread, rthread;

    Node(int val) {
        data = val;
        left = right = nullptr;
        lthread = rthread = true;
    }
};

class ThreadedBinaryTree {
private:
    Node* root;

public:
    ThreadedBinaryTree() {
        root = nullptr;
    }

    void insert(int val) {
        Node* ptr = root;
        Node* parent = nullptr;

        // Find the parent to which new node is to be attached
        while (ptr != nullptr) {
            if (val == ptr->data) {
                cout << "Duplicate value not allowed.\n";
                return;
            }

            parent = ptr;

            if (val < ptr->data) {
                if (!ptr->lthread)
                    ptr = ptr->left;
                else
                    break;
            } else {
                if (!ptr->rthread)
                    ptr = ptr->right;
                else
                    break;
            }
        }

        Node* newNode = new Node(val);

        if (parent == nullptr) {
            root = newNode;
        } else if (val < parent->data) {
            newNode->left = parent->left;
            newNode->right = parent;
            parent->lthread = false;
            parent->left = newNode;
        } else {
            newNode->right = parent->right;
            newNode->left = parent;
            parent->rthread = false;
            parent->right = newNode;
        }

        cout << val << " inserted.\n";
    }

    // In-order traversal without recursion or stack
    void inorder() {
        Node* ptr = root;

        // Find the leftmost node
        if (ptr == nullptr) {
            cout << "Tree is empty.\n";
            return;
        }

        while (!ptr->lthread)
            ptr = ptr->left;

        cout << "In-order traversal: ";
        while (ptr != nullptr) {
            cout << ptr->data << " ";

            // If right thread exists, go to inorder successor
            if (ptr->rthread)
                ptr = ptr->right;
            else {
                // Otherwise go to leftmost of right subtree
                ptr = ptr->right;
                while (ptr != nullptr && !ptr->lthread)
                    ptr = ptr->left;
            }
        }
        cout << endl;
    }
};

int main() {
    ThreadedBinaryTree tbt;
    int choice, val;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert\n2. In-order Traversal\n3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> val;
            tbt.insert(val);
            break;
        case 2:
            tbt.inorder();
            break;
        case 3:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 3);

    return 0;
}
