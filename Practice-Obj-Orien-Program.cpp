#include <iostream>

using namespace std;

class Rectangle
{
    private:
    int length;
    int width;

public:

void intialize(int l, int w){
    length = l;
    width = w;
   
}

int area() {
    return length * width;
}
int perimeter(){
    return 2*(length + width);
}


};

int main()
{

    Rectangle r;

     int l,w;
     cout << "Enter Length and Breadth ";

     cin  >>l >>w;

     r.intialize(l,w);

    

    cout << r.area()<<endl;
    cout <<  r.perimeter();



    return 0;
}