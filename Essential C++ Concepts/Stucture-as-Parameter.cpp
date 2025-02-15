
#include <iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Rectangle{
    int length;
    int width;
};

void passbyValue(struct Rectangle r){
    r.length = 20;
    cout << "Length " << r.length <<endl;
    cout << "Width " << r.width <<endl;
}

void passbyAddress(struct Rectangle *p){
    p->width = 30;
    cout << "Length " << p->length <<endl;
    cout << "Width " << p->width <<endl;
}

struct Rectangle *func(){
    struct Rectangle *p;
    p = new Rectangle;

    p->length = 18;
    p->width = 22;

    return p;
}

int main()
{   
    cout << "Returning a Address of a Stucture" <<endl;
   
    struct Rectangle *ptr =func();
   
    cout << ptr->length <<endl;
    cout << ptr->width <<endl;


    cout << "Passing a Value" <<endl;
    struct Rectangle r={10,5};

    passbyValue(r);

    printf("Length %d\n Breadth %d\n", r.length,r.width);
    

    cout << "Pass Address of the Rectangle " <<endl;

    passbyAddress(&r);

    
    return 0;
}


