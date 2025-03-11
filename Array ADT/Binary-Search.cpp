#include <iostream>

using namespace std;

struct Array{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr){

    cout << " Elements are " << " " ;
    for (int i = 0; i < arr.length; i++)
    {
        cout << arr.A[i] << " " ;
    }
    
}

int BinarySearch(struct Array arr, int key){
    int l, mid, h;
    l = 0;
    h = arr.length -1;

    while (l<=h)
    {
        mid = (l+h)/2;
        if (key ==arr.A[mid])
        {
            return mid;
        }
        else if (key < arr.A[mid])
            h = mid -1;
        
        else 
            l = mid +1;
        
    }
    return -1;
    
}

int RbinSearch(int a[], int l, int h, int key)
{
    int mid;

    if(l<=h){
        mid = (l+h)/2;
        if(key == a[mid])
            return mid;
        else if(key < a[mid])
            return RbinSearch(a,l, mid-1, key);
        else
        return RbinSearch(a, mid+1, h, key);
    }
    return -1;
}
int main()
{
    struct Array arr = {{2, 4, 6 ,7,8, 10, 11, 13, 14, 16}, 10, 5};

    cout << BinarySearch(arr, 2);

    Display(arr);

    cout << "Recursive Binary Search " <<RbinSearch(arr.A,0,arr.length, 6);
    
    

    return 0;
}