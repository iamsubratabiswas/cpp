//Constants
//  Write a function that takes an integer and returns the factorial of that number. Declare function parameter as
// const. Call the function with some argument from main function, store the result and print it.

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
