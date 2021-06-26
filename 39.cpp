// Inheritance
// Write empty class declarations for the following class hierarchy.
//  Base1 <--- Derived -----> Base2
 

#include <iostream>

using namespace std;

class Base1 {};
class Base2 {};
class Derived : public Base1, public Base2 {};

int main() {
    Derived d;
}
