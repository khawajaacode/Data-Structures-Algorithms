#include<iostream>

using namespace std;

struct  Rectangle
{
    int length;
    int width;
};


int main() {
    Rectangle r= {10, 5};

    cout << r.length <<endl;
    cout << r.width << endl;

    
     
    Rectangle *p;
    // Create Rectangle obj in Heap
     p = new Rectangle;
    // p=&r;

    p->length = 15;
    p->width = 7;

    cout << p->length<<endl;
    cout << p->width <<endl;

}