#include <iostream>

using namespace std;

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

void Selection(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[minIndex])
                minIndex = j;
        }
        swap(A[minIndex], A[i]);
    }
}

int main() {
    int A[] = {9, 1, 3, 2, 10}, n = 5;

    cout << "Selection Sort: ";
    Selection(A, n);

    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }

    return 0;
}