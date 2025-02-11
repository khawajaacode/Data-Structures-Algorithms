#include<iostream>

using namespace std;

int main() {

    int arr[5];

    cout << sizeof(arr) << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << "Enter the Value at index " << i << " : ";
        cin >> arr[i]; 
    }
    for (int i = 0; i < 5; i++)
    {
        
        cout << "\n Values You Enter : " << arr[i];
    }
    cout << endl;

    for (int i = 4; i >=0; i--)
    {
        
        cout << "\n Reversed : " << arr[i];
    }
    cout << endl;
}