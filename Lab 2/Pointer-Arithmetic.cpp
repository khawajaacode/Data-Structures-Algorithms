#include <iostream>

using namespace std;

int main()
{

    int arr[5] = {40, 332, 12,353, 70};

    int* ptr = arr;

    int sum = 0;

    for (int i = 0; i <5; i++)
    {
        sum += *(ptr + i);
    }
    
    cout << "Sum " << sum;

    return 0;
}