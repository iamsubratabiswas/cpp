#include <iostream>

using namespace std;

inline int add(int a, int b = 0, int c = 0) { return a + b + c; }

int main() {
    // 3 values
    cout << "Calling add() with 3 values : " << endl;
    cout << "1 + 2 + 3 = ";
    cout << add(1, 2, 3) << endl;

    // 2 values
    cout << "Calling add() with 2 values : " << endl;
    cout << "1 + 2 = ";
    cout << add(1, 2) << endl;

    // 1 values
    cout << "Calling add() with 1 values : " << endl;
    cout << "1 = ";
    cout << add(1) << endl;
}
