#include <iostream>

using namespace std;

int main()
{

    int data =  5;
    int* ptr = &data;
    cout << data << endl;

    *ptr = 8;
    cout << data << endl;

    return 0;
}