// Reference

// Now write another function swap() that takes two strings (character array) and interchanges them without
// reference parameters. Test this function using some arguments. Rewrite the function using reference parameters.
// Again test this function with some arguments.

#include <iostream>

using namespace std;

void swap1(string x, string y ) {
    string temp = x;
    x = y;
    y = temp;
}

void swap2(string& x, string& y ) {
    string temp = x;
    x = y;
    y = temp;
}

int main() {
    string a = "String 1";
    string b = "String 2";
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    swap1(a, b);
    cout << "After calling swap1() [Without reference parameters]" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << endl;
    string c = "String 3";
    string d = "String 4";
    cout << "c = " << c << endl;
    cout << "d = " << d << endl;
    swap2(c, d);
    cout << "After calling swap2() [With reference parameters]" << endl;
    cout << "c = " << c << endl;
    cout << "d = " << d << endl;
}
