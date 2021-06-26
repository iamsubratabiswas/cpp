#include <iostream>
#include <chrono>

using namespace std;

// inline version
inline int inlineAdd(int a, int b, int c) {
    return a + b + c;
}

// non-inline version 
int nonInlineAdd(int a, int b, int c) {
    return a + b + c;
}

int main() {
    int sum;

    // inline version : 
    cout << "Time for inline version : "; 
    auto start1 = chrono::high_resolution_clock::now();
    sum = inlineAdd(1, 2, 3);
    auto finish1 = chrono::high_resolution_clock::now();
    cout << chrono::duration_cast<chrono::nanoseconds>(finish1-start1).count() << "ns\n";
    // non-inline version : 
    cout << "Time for non-inline version : "; 
    auto start2 = chrono::high_resolution_clock::now();
    sum = nonInlineAdd(1, 2, 3);
    auto finish2 = chrono::high_resolution_clock::now();
    cout << chrono::duration_cast<chrono::nanoseconds>(finish2-start2).count() << "ns\n";
}
