// Inheritance
//  Write a program to illustrate the role of virtual destructor.



#include <iostream>

using namespace std;

class Base1 {
    public : 
    Base1() {cout << "Base1 ctor" <<endl;}
    ~Base1() {cout << "Base1 dtor" <<endl;}
};

class Derived1 : public Base1 {
    public : 
    Derived1() {cout << "Derived1 ctor" <<endl;}
    ~Derived1() {cout << "Derived1 dtor" <<endl;}
};

class Base2 {
    public : 
    Base2() {cout << "Base2 ctor" <<endl;}
    virtual ~Base2() {cout << "Base2 dtor" <<endl;}
};

class Derived2 : public Base2 {
    public : 
    Derived2() {cout << "Derived2 ctor" <<endl;}
    ~Derived2() {cout << "Derived2 dtor" <<endl;}
};

int main() {
    Base1* b1ptr = new Derived1;
    Base2* b2ptr = new Derived2;
    cout << "\nBase1 has normal dtor and Base2 has virtual dtor" << endl;
    cout << "\nDeleting Derived1 using Base1 pointer : " << endl;
    delete b1ptr;
    cout << "\nDerived1 dtor not called!" << endl;
    cout << "\nDeleting Derived2 using Base2 pointer : " << endl;
    delete b2ptr;
    cout << "\nDerived2 dtor called!" << endl;
}
