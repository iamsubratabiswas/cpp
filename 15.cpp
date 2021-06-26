#include <iostream>

using namespace std;

int max(int a, int b, int c) {
    if (a > b && a > c) return a;
    if (b > c) return b;
    return c;
}

int max(int arr[], int size) {
    int max = arr[0];
    for (int i = 0; i < size; i++) 
        if (arr[i] > max)
            max = arr[i];
    return max;
}

int main() {
   int arr[] = {5, 2, 6, 8, 0, -5, 10};
   cout << "Max of three : " << max(arr[0], arr[1], arr[2]) << endl;
   cout << "Max of array : " << max(arr, 7) << endl;; 
}
