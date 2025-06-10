#include <iostream>
#include <vector>
#include <queue>
#include <stdexcept>

using namespace std;  // Added here to apply to the entire program

// Node and Queue class for Task 1: Linked List Queue
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;
    int size;
public:
    Queue() : front(nullptr), rear(nullptr), size(0) {}
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
    void enqueue(int x) {
        Node* newNode = new Node(x);
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }
    int dequeue() {
        if (isEmpty()) {
            throw out_of_range("Queue is empty");
        }
        int data = front->data;
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        size--;
        return data;
    }
    int getFront() {
        if (isEmpty()) {
            throw out_of_range("Queue is empty");
        }
        return front->data;
    }
    bool isEmpty() {
        return front == nullptr;
    }
    int getSize() {
        return size;
    }
    void print() const {
        Node* current = front;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

// Task 2: STL Queue Demonstration
void demonstrateSTLQueue() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << "STL Queue - Size: " << q.size() << ", Front: " << q.front() << endl;
    q.pop();
    cout << "After pop, Front: " << q.front() << endl;
}

// Task 3: Binary Representation and Enqueue
void binaryAndEnqueue() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    if (n <= 0) {
        cout << "Please enter a positive integer." << endl;
        return;
    }
    Queue q;
    int highest_bit = 31 - __builtin_clz(n);
    cout << "Binary representation: ";
    for (int i = highest_bit; i >= 0; --i) {
        int bit = (n & (1 << i)) ? 1 : 0;
        cout << bit;
        q.enqueue(bit);
    }
    cout << endl;
    cout << "Queue contents: ";
    while (!q.isEmpty()) {
        cout << q.dequeue() << " ";
    }
    cout << endl;
}

// Task 4: Bank Queue Simulation with 3 Counters
void bankQueueSimulation() {
    vector<Queue> counters(3);
    int next_person_id = 1;
    while (true) {
        cout << "\nBank Queue Simulation\n";
        cout << "1. Add person to counter 1\n";
        cout << "2. Add person to counter 2\n";
        cout << "3. Add person to counter 3\n";
        cout << "4. Serve next at counter 1\n";
        cout << "5. Serve next at counter 2\n";
        cout << "6. Serve next at counter 3\n";
        cout << "7. Display all queues\n";
        cout << "8. Exit\n";
        cout << "Choice: ";
        int choice;
        cin >> choice;
        if (choice == 8) {
            break;
        } else if (choice >= 1 && choice <= 3) {
            int counter_index = choice - 1;
            counters[counter_index].enqueue(next_person_id);
            cout << "Person " << next_person_id << " added to counter " << (counter_index + 1) << endl;
            next_person_id++;
        } else if (choice >= 4 && choice <= 6) {
            int counter_index = choice - 4;
            if (counters[counter_index].isEmpty()) {
                cout << "No one in queue at counter " << (counter_index + 1) << endl;
            } else {
                int person = counters[counter_index].dequeue();
                cout << "Serving person " << person << " at counter " << (counter_index + 1) << endl;
            }
        } else if (choice == 7) {
            for (int i = 0; i < 3; ++i) {
                cout << "Counter " << (i + 1) << ": ";
                counters[i].print();
            }
        } else {
            cout << "Invalid choice\n";
        }
    }
}

int main() {
    cout << "Task 1: Linked List Queue implemented above.\n";
    cout << "Task 2: Demonstrating STL Queue:\n";
    demonstrateSTLQueue();
    cout << "\nTask 3: Binary Representation and Enqueue:\n";
    binaryAndEnqueue();
    cout << "\nTask 4: Bank Queue Simulation:\n";
    bankQueueSimulation();
    return 0;
}