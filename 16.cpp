#include <iostream>

// learn other way if it exists
#define MAXSIZE 100

using namespace std;

void print(int arr[], int size) {
    for (int i = 0; i < size; i++) 
    cout << arr[i] << " ";
    cout << endl;
}

void print(int arr[MAXSIZE][MAXSIZE], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arr1[MAXSIZE] = {1, 2, 3};
    int arr2[MAXSIZE][MAXSIZE] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << "Printing vector : " << endl;
    print(arr1, 3);
    cout << "Printing matrix : " << endl;
    print(arr2, 3, 3);
}
