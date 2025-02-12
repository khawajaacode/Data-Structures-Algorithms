#include <iostream>

using namespace std;

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b =  temp ;
}

void swap11(int &x, int &y){
    int temp1;

    temp1 = x;
    x = y;
    y = temp1;
}


int main(){

    cout << "Call By Address Function" <<endl;

    int num1 = 10, num2 = 15;
    swap(&num1,&num2);

    cout << "First Number " << num1 <<endl;
    cout << "Second Number " << num2 <<endl;

    cout << "Call by Refrence";
    int var = 12, var1 = 22;
    
    swap11(var,var1);

    cout << "First Number " << var <<endl;
    cout << "Second Number " << var1 <<endl;

}

