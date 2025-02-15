#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int length = 0, breadth = 0;
    printf("Enter the Length and Width : ");
    cin >> length >> breadth;

    int area = length * breadth;
    int peri = 2*(length + breadth);

    cout << area << endl;
    cout << peri;
    

    return 0;
}