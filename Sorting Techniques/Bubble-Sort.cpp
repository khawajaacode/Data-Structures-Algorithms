#include <iostream>

using namespace std;

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void Bubble(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) { 
            if (A[j] > A[j + 1]) {
                swap(&A[j], &A[j + 1]); 
            }
        }
    }
}

int main() {
    int A[] = {11, 2, 4, 6, 0};
    int n = 5;

    cout << "Bubble Sort: ";
    Bubble(A, n);

    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }

    return 0;
}