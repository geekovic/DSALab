#include <iostream>
using namespace std;

// Node structure for polynomial term
class Node {
public:
    int coeff;
    int exp;
    Node* next;

    Node(int c, int e) {
        coeff = c;
        exp = e;
        next = nullptr;
    }
};

// Class to handle polynomial as linked list
class Polynomial {
private:
    Node* head;

public:
    Polynomial() {
        head = nullptr;
    }

    // Function to insert term in decreasing order of exponent
    void insertTerm(int coeff, int exp) {
        Node* newNode = new Node(coeff, exp);
        if (head == nullptr || exp > head->exp) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            Node* prev = nullptr;
            while (current != nullptr && current->exp > exp) {
                prev = current;
                current = current->next;
            }

            if (current != nullptr && current->exp == exp) {
                current->coeff += coeff;
                delete newNode;
                if (current->coeff == 0) { // Optional: remove zero-coeff term
                    if (prev)
                        prev->next = current->next;
                    else
                        head = current->next;
                    delete current;
                }
            } else {
                newNode->next = current;
                if (prev)
                    prev->next = newNode;
                else
                    head = newNode;
            }
        }
    }

    // Function to add two polynomials
    static Polynomial add(Polynomial& p1, Polynomial& p2) {
        Polynomial result;
        Node* a = p1.head;
        Node* b = p2.head;

        while (a != nullptr && b != nullptr) {
            if (a->exp == b->exp) {
                result.insertTerm(a->coeff + b->coeff, a->exp);
                a = a->next;
                b = b->next;
            } else if (a->exp > b->exp) {
                result.insertTerm(a->coeff, a->exp);
                a = a->next;
            } else {
                result.insertTerm(b->coeff, b->exp);
                b = b->next;
            }
        }

        while (a != nullptr) {
            result.insertTerm(a->coeff, a->exp);
            a = a->next;
        }

        while (b != nullptr) {
            result.insertTerm(b->coeff, b->exp);
            b = b->next;
        }

        return result;
    }

    // Function to display the polynomial
    void display() {
        if (head == nullptr) {
            cout << "0" << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->coeff << "x^" << temp->exp;
            if (temp->next != nullptr)
                cout << " + ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Polynomial poly1, poly2;

    cout << "Enter first polynomial (in form: coeff exp). Enter -1 -1 to stop:\n";
    int c, e;
    while (true) {
        cin >> c >> e;
        if (c == -1 && e == -1)
            break;
        poly1.insertTerm(c, e);
    }

    cout << "Enter second polynomial (in form: coeff exp). Enter -1 -1 to stop:\n";
    while (true) {
        cin >> c >> e;
        if (c == -1 && e == -1)
            break;
        poly2.insertTerm(c, e);
    }

    cout << "\nFirst Polynomial: ";
    poly1.display();
    cout << "Second Polynomial: ";
    poly2.display();

    Polynomial result = Polynomial::add(poly1, poly2);
    cout << "Resultant Polynomial (Sum): ";
    result.display();

    return 0;
}
