
#include <iostream>

using namespace std;

void Insertion(int A[], int n){
    int i,j, x;
    for(i = 1; i <n;i++){
        j=i-1;
        x=A[i];
        while(j >=0 && A[j]>x){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}

int main() {
 
    
    int A[] = {10,11,8,4,1,200,90,2}, n=8, i;
    
    Insertion(A,n);
    
    for(i=0; i<8;i++){
        cout << A[i] << " " ;
    }

    return 0;
}