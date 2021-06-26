
//Reference
// Check if a swap function using reference takes more or less time than one using non-reference.

#include <iostream>
#include <chrono>

using namespace std;

void pointerSwap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void referenceSwap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 10, b = 20;

    // Timing swap with reference
    cout << "Time for swap with reference : "; 
    auto start2 = chrono::high_resolution_clock::now();
    referenceSwap(a, b);

    auto finish2 = chrono::high_resolution_clock::now();
    cout << chrono::duration_cast<chrono::nanoseconds>(finish2-start2).count() << "ns\n";

    // Timing swap without reference 
    cout << "Time for swap without reference : "; 
    auto start1 = chrono::high_resolution_clock::now();
    pointerSwap(&a, &b);
    auto finish1 = chrono::high_resolution_clock::now();
    cout << chrono::duration_cast<chrono::nanoseconds>(finish1-start1).count() << "ns\n";
}
