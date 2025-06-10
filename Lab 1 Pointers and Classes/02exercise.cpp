#include <iostream>

using namespace std;

int main()
{

    int data[5];
    cout << "Enter 5 integers: ";
    for (int i = 0; i < 5; i++)
    {

        cin >> data[i];
    }
     int* ptr = data + 4; // Point to the last element of the array
    for (int i = 0; i < 5; i++)
    {
        cout << *ptr << " "; // Dereference the pointer to get the value
        ptr--; // Move the pointer to the previous element
    }

    return 0;
}