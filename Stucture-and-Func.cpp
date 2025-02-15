#include <iostream>

using namespace std;

struct Rectangle
{
    int length;
    int width;
};
void intialize(Rectangle *r, int l, int w){
    r->length = l;
    r->width = w;
    
}

int area(struct Rectangle r) {
    return r.length * r.width;
}
int perimeter( Rectangle r){
    return 2*(r.length + r.width);
}
int main()
{

    Rectangle r;

    int l,w;
    cout << "Enter Length and Breadth ";

    cin  >>l >>w;

    intialize(&r, l, w);

    int a = area(r);
    int p = perimeter(r);

    cout << "Area " << a<<endl;
    cout << "Perimeter " << p <<endl;

    return 0;
}