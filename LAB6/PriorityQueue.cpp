PRIORITY QUEUE

#include <iostream>
#include <vector>

using namespace std;

class PriorityQueue {
private:
    vector<int> heap; // Vector to store heap elements

    // Heapify up: Maintain max-heap property after insertion
    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        while (index > 0 && heap[index] > heap[parent]) {
            swap(heap[index], heap[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    // Heapify down: Maintain max-heap property after deletion
    void heapifyDown(int index) {
        int size = heap.size();
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < size && heap[left] > heap[largest])
                largest = left;
            if (right < size && heap[right] > heap[largest])
                largest = right;

            if (largest != index) {
                swap(heap[index], heap[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

public:
    // Insert element into the priority queue
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
        cout << "Inserted: " << value << endl;
    }

    // Remove the highest priority (maximum) element
    void deleteMax() {
        if (heap.empty()) {
            cout << "Priority Queue is empty!" << endl;
            return;
        }
        cout << "Removed: " << heap[0] << endl;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    // Get the maximum element (highest priority)
    int getMax() {
        if (heap.empty()) {
            cout << "Priority Queue is empty!" << endl;
            return -1;
        }
        return heap[0];
    }

    // Display elements of the priority queue
    void display() {
        if (heap.empty()) {
            cout << "Priority Queue is empty!" << endl;
            return;
        }
        cout << "Priority Queue elements: ";
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }
};

// Main function
int main() {
    PriorityQueue pq;

    pq.insert(40);
    pq.insert(20);
    pq.insert(30);
    pq.insert(50);
    pq.insert(10);

    pq.display();

    cout << "Max Element: " << pq.getMax() << endl;

    pq.deleteMax();
    pq.display();

    return 0;
}
