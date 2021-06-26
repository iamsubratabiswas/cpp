#include <iostream>

using namespace std;

class Rectangle {
    double length; 
    double breadth; 

   public:
    Rectangle(double length = 1, double breadth = 1) {
        this->length = length;
        this->breadth = breadth;
    }

    double area() {
        return length * breadth;
    }
};

int main() {
    Rectangle a(2,4), b(3,5), c(2,2), d(10, 15);
    cout << "Area of rectangle a : " << a.area() << endl;
    cout << "Area of rectangle b : " << b.area() << endl;
    cout << "Area of rectangle c : " << c.area() << endl;
    cout << "Area of rectangle d : " << d.area() << endl;
}
