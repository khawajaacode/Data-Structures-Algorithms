#include<iostream>

using namespace std;

int main() {

    int var = 10;
    int &ref = var;

    cout << var <<endl <<ref<<endl;

    

    int b = 30;
    b = ref;

    cout <<var<<endl <<ref;

    

}