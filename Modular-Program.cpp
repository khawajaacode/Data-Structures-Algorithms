#include <iostream>

using namespace std;

int area(int length, int width) {
    return length * width;
}
int perimeter(int length, int width){
    return 2*(length + width);
}
int main()
{

    int length = 0, width = 0;
    cout << "Enter Length and Breadth ";

    cin  >> length >>width;

    int a = area(length, width);
    int p = perimeter(length, width);

    cout << "Area " << a<<endl;
    cout << "Perimeter " << p <<endl;

    return 0;
}