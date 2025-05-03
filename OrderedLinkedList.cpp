#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class OrderedLinkedList {
private:
    Node* head;

public:
    OrderedLinkedList() {
        head = nullptr;
    }

    // Function to insert a new node in order
    void insert(int val) {
        Node* newNode = new Node(val);

        // Case 1: Insert at beginning or empty list
        if (head == nullptr || val < head->data) {
            newNode->next = head;
            head = newNode;
            return;
        }

        // Case 2: Traverse to find correct position
        Node* current = head;
        while (current->next != nullptr && current->next->data < val) {
            current = current->next;
        }

        // Insert after current
        newNode->next = current->next;
        current->next = newNode;
    }

    // Function to display the list
    void display() {
        Node* temp = head;
        cout << "Ordered Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Destructor to free memory
    ~OrderedLinkedList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    OrderedLinkedList list;
    int choice, value;

    do {
        cout << "\nMenu:\n1. Insert\n2. Display\n3. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                list.insert(value);
                break;
            case 2:
                list.display();
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);

    return 0;
}
