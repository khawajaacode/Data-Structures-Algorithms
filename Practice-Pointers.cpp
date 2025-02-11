#include<iostream>

using namespace std;

int main() {

    int A= 20;
    
    int *ptr;

    ptr = &A;

    cout << A << endl << *ptr <<" " <<  &A<<endl;
cout <<endl;
    int arr[5] = {2, 4, 6,8,10};
     int *p;
     p =arr;
    for (int i = 0; i < 5; i++)
    {
    cout << arr[i]<<" ";
    
    }

    cout <<endl << "Using pointer ";



     for (int i = 0; i < 5; i++) {
            cout << p[i]<<" ";
    }
    cout << endl;
    
    
    cout << "\n  Heap Memory" <<endl;

    
    
    int *ptrr;
     ptrr = new int[5];

     ptrr[0] = 10;
     ptrr[1] = 11;
     ptrr[2] = 12;
     ptrr[3] = 13;
     ptrr[4] = 14;


     for (int i = 0; i < 5; i++)
     {
        cout << ptrr[i] <<endl;
     }
    
     delete [ ] ptrr;
    //In C free(ptrr);


     cout << "\n Size of Pointer with Differ Data type: " << endl;





     int *p1;
     char *p2;
     float *p3;
     double *p4;

     struct  Rectangle *p5;


     cout << sizeof(p1) <<endl;
     cout << sizeof(p2) <<endl;
     cout << sizeof(p3) <<endl;
     cout << sizeof(p4) <<endl;
     cout << sizeof(p5) <<endl;
}


struct Rectangle
{
    int length, width;
};
