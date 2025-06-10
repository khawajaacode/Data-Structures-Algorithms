#include <iostream>

using namespace std;

int main()
{

    int* data = new int[5];

    cout << "Enter Numbers ";
    for (int i = 0; i < 5; i++)
    {
        cin >> data[i];
    }
    cout << "----------------------" <<endl;

    int max =  data[0];
    for (int i = 0; i < 5; i++)
    {
        if (data[i] > max)
        {
            max = data[i];
        }
        
    }

    cout << "Max number is " << max;

    delete data;
     
    
    return 0;
}