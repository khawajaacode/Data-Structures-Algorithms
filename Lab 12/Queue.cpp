#include <iostream>
using namespace std;

// Define a Queue class to implement queue operations using an array
class Queue {
private:
    static const int SIZE = 5; // Maximum size of the queue
    int queue[SIZE];           // Array to store queue elements
    int front;                 // Index of the front element
    int rear;                  // Index of the rear element

public:
    // Constructor: Initializes front and rear to -1 (empty queue)
    Queue() : front(-1), rear(-1) {}

    // Enqueue: Inserts an element at the rear of the queue
    void Enqueue(int data) {
        // Check if queue is full
        if (rear >= SIZE - 1) {
            cout << "Queue Overflow" << endl;
            return;
        }
        // If queue is empty, set front to 0
        if (front == -1) {
            front = 0;
        }
        queue[++rear] = data; // Increment rear and add element
    }

    // Dequeue: Removes and returns the front element from the queue
    int Dequeue() {
        // Check if queue is empty
        if (front == -1 || front > rear) {
            cout << "Queue Underflow" << endl;
            return -1; // Error value
        }
        int data = queue[front]; // Store front element
        front++;                 // Move front to next element
        // Reset if queue becomes empty
        if (front > rear) {
            front = rear = -1;
        }
        return data; // Return removed element
    }

    // Front: Returns the first element without removing it
    int Front() const {
        // Check if queue is empty
        if (front == -1 || front > rear) {
            cout << "Queue is empty" << endl;
            return -1; // Error value
        }
        return queue[front]; // Return front element
    }

    // isEmpty: Checks if the queue has no elements
    bool isEmpty() const {
        return front == -1 || front > rear; // True if empty
    }

    // Utility function: Prints the current queue contents
    void printQueue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "[";
        for (int i = front; i <= rear; i++) {
            cout << queue[i];
            if (i < rear) cout << ", ";
        }
        cout << "]" << endl;
    }
};

// Main function to demonstrate queue operations
int main() {
    Queue q; // Create a queue object

    // Enqueue 5
    cout << "Operation: Enqueue(5)" << endl;
    q.Enqueue(5);
    cout << "Queue Content: "; q.printQueue(); // [5]
    cout << "Front: " << q.Front() << endl;   // 5

    // Enqueue 9
    cout << "\nOperation: Enqueue(9)" << endl;
    q.Enqueue(9);
    cout << "Queue Content: "; q.printQueue(); // [5, 9]
    cout << "Front: " << q.Front() << endl;   // 5

    // Dequeue
    cout << "\nOperation: Dequeue()" << endl;
    int dequeued = q.Dequeue();               // Removes 5
    if (dequeued != -1) {
        cout << "Dequeued: " << dequeued << endl; // 5
    }
    cout << "Queue Content: "; q.printQueue(); // [9]
    cout << "Front: " << q.Front() << endl;   // 9

    return 0;
}