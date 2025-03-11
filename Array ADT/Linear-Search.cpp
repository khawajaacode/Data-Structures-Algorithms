#include <iostream>

using namespace std;

void swap(int *a, int *b){
    int temp =*a;
    *a = *b;
    *b = temp;
}

struct Array{
  int A[10];
  int size;
  int length;
};

void Display(struct Array arr){
    cout << "\nElements are "<<endl;
    for(int i = 0; i < arr.length; i++){
        cout <<endl<< arr.A[i];
    }
}

int LinearSearch(struct Array *arr, int key){
    for(int i = 0; i < arr->length;i++){
        if(key ==arr->A[i]){
        swap(&arr->A[i],&arr->A[0]);
        return i;
        }
    }
return -1;
}
int main()
{
struct Array arr = {{2,23,14,5,6,8,9,12},10,8};
cout << LinearSearch(&arr, 24);
Display(arr);
    


    return 0;
}


