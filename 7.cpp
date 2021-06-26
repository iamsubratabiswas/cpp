#include <iostream>

using namespace std;

long factorial(const int n) {
    long fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int n;
    cout<<"Enter an integer: "<<endl;
    cin>>n;
    long fact = factorial(n);
    cout << n << "! = " << fact << endl; 
}
