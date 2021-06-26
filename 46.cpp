// Exception Handling
//  Two integers are taken from keyboard. Then perform division operation. Write a try block to throw an exception
// when division by zero occurs and appropriate catch block to handle the exception thrown.

#include <iostream>

using namespace std;

class DivisionByZero {};

double division(int a, int b) {
    if (b == 0)
        throw DivisionByZero();
    else
        return (double)a / b;
}

int main() {
    int a, b;
    cout << "Enter two integers : ";
    cin >> a >> b;
    try {
        double r = division(a, b);
        cout << a << " / " << b << " = " << r << endl;
    } catch (DivisionByZero dbz) {
        cout << "Second int is 0 and division by zero is not allowed!" << endl;
    }
}
