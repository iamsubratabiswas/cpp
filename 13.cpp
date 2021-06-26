// Inline function
// Write an inline function add() that takes three integer arguments and returns the sum of these arguments

#include <iostream>

using namespace std;

inline int add(int a, int b, int c) {
    return a + b + c;
}

int main() {
    cout << "1 + 2 + 3 = ";
    cout << add(1, 2, 3) << endl;
}
