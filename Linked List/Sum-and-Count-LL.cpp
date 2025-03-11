#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};

Node* create(int A[], int n) {
    if (n == 0) return nullptr;
    Node *first = new Node(A[0]);
    Node *last = first;

    for (int i = 1; i < n; i++) {
        Node *t = new Node(A[i]);
        last->next = t;
        last = t;
    }
    return first;
}

void displayNormal(Node *p){
    if(p!= NULL){
        cout << p->data<< " ";
        displayNormal(p->next);
    }
}

void displayReverse(Node *p) {
    if (p != nullptr) {
        displayReverse(p->next);
        cout << p->data << " ";
    }
}

void deleteList(Node *&first) {
    Node *p = first;
    while (p) {
        Node *temp = p;
        p = p->next;
        delete temp;
    }
    first = nullptr;
}

int count(Node *p){
    int l=0;
    while (p)
    {
        l++;
        p=p->next;

    }
    return l;
    
}
int Rcount(Node *p){
    if(p!=NULL)
        return Rcount(p->next) +1;
    else
        return 0;
}


int sum(Node *p){
    int sum = 0;
    while (p!=NULL)
    {
        sum+=p->data;
        p=p->next;
    }
    return sum;
    
}

int Rsum(Node *p) {

    if (p==NULL)
        return 0;
    else
        return Rsum(p->next) + p->data;
    
    
}




int main() {
    int A[] = {3, 5, 7, 10, 25, 8, 32, 2};
    Node *first = create(A, 8);
    cout << "Length is " <</*count(first)*/ Rcount(first)<<endl;

    cout << "Sum is " <<sum(first) <<endl;

    displayNormal(first);

    cout << endl;
    deleteList(first);
    return 0;
}

