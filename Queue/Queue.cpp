#include <iostream>

using namespace std;

class Queue {
    private:
    int front;
    int rear;
    int size;
    int *Q;

    public:
    Queue() {
        front = rear = -1;
        size = 5;
        Q = new int[size];
    }

    Queue(int size) {
        this->size = size;
        front = rear = -1;
        Q = new int[this->size];

    }
    void Display();
    void enqueue(int x);
    int dequeue();

};

void Queue::enqueue(int x) {
    
    if(rear == size -1){
    cout << "Queue Full";
        return;
    }

    
        rear++;
        Q[rear] = x;
    
   
}

int Queue::dequeue() {

    int x =-1;
    if (front == rear)
    {
        cout << "Queue is Empty";
        return -1;
    }
   
        front++;
        x=Q[front];
        return x;
    
}

void Queue::Display(){
    for(int i = front+1; i <=rear; i++){
        cout << " " <<  Q[i] <<endl;
    }

}


int main()
{
    Queue q;

    q.enqueue(10);
    
    q.enqueue(20);
    
    q.enqueue(30);
    
    q.Display();

    q.dequeue();

    cout << "Deque";q.Display();

    return 0;
}