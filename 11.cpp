#include <iostream>

using namespace std;

long factorial(const int& n) {
    long fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int n = 7;
    long fact = factorial(n);
    cout << n << "! = " << fact << endl; 
    n=8;
    fact = factorial(n);
    cout << n << "! = " << fact << endl; 
}
