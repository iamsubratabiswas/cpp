// Classes and Objects
// . Write some programs to understand the notion of constant member functions, mutable data members etc.


#include <iostream>

using namespace std;

class MutableData {
    int x;
    mutable int y;
    public : 
    MutableData(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    } 

    void constFun() const {
        cout << "In constFun()" << endl;
        // x;  not possible!
        cout << "Changed value of y from " << y++ << " to " << y << endl;
    }
};

int main() {
    MutableData md(5, 6);
    md.constFun();
}
