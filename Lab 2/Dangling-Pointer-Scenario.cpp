#include <iostream>
using namespace std;


int* createDanglingPointer() {
    int localVar = 42;
    return &localVar; // Warning: Returning address of a local variable
}

int main() {
    int* ptr = createDanglingPointer();
    cout << *ptr << std::endl; // Undefined behavior
    return 0;
}
