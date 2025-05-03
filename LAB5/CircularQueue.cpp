CIRCULAR QUEUE

#include <iostream>
using namespace std;

#define SIZE 5 // Define the maximum size of the queue

class CircularQueue {
private:
    int front, rear;
    int arr[SIZE]; // Array to store queue elements

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // Check if queue is full
    bool isFull() {
        return (front == 0 && rear == SIZE - 1) || (rear + 1 == front);
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Enqueue operation
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full! Cannot insert " << value << endl;
            return;
        }

        // First element to be inserted
        if (front == -1) front = 0;

        // Circular increment of rear
        rear = (rear + 1) % SIZE;
        arr[rear] = value;

        cout << "Inserted " << value << endl;
    }

    // Dequeue operation
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue." << endl;
            return;
        }

        cout << "Removed " << arr[front] << endl;

        // If only one element was present
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }

    // Get front element
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    // Get rear element
    int getRear() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[rear];
    }

    // Display queue elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

// Main function
int main() {
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50); // Queue is now full

    q.display();

    q.dequeue();
    q.enqueue(60); // Inserting after deletion (circular behavior)
    
    q.display();

    cout << "Front: " << q.getFront() << endl;
    cout << "Rear: " << q.getRear() << endl;

    return 0;
}
