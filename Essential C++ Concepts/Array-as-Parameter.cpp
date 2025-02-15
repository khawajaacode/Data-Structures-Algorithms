#include<iostream>

using namespace std;

// void func(int A[]/* *A */,int n) {
//     //A[0] = 15;
//     for(int i=0;i<n;i++)
//     cout << A[i] <<endl;
// }

// int * fun(int size){
//     int *p;
//     p = new int[size];

//     for (int i = 0; i < size; i++)
//     {
//         p[i] = i+1;
//     }
//     return p;
// }


// int main() {

//     int *ptr, sz=7;
    
//     ptr = fun(sz);


//     for (int i = 0; i < sz; i++)
//     {
//         cout << ptr[i]<<endl;
//     }
    







//     // int A[] = {2,4,6,8,10};

//     // int n = 5;

//     // func(A,n);

//     // for ( int x:A) {
//     // cout <<x <<" ";
//     // }

    
// }

int * arr(int size){
    int *p;
    p =new int[size];
    for (int i = 0; i < size; i++)
    {
        p[i]= i+1;
    }

    return p;
    
}

void func(int *A, int n){
    
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " "<<endl;
    }
    
}


int main() {

    int A[] = {3,6,9,12};
    int n = 5;

    func(A, n);

    for(int x:A) {
        cout << x <<endl;

    }
    











    // int *ptr, sz=10;

    // ptr = arr(sz);

    // for (int i = 0; i < sz; i++)
    // {
    //     cout << ptr[i]<<endl; 
    // }
    
    // return 0;
}

