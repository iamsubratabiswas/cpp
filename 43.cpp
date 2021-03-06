// Inheritance
//  Write class definitions for the following class hierarchy
//   Circle--> Shape2D <---Rectangle
// The Shape2D class represents two dimensional shapes that should have pure virtual functions area(), perimeter()
// etc. Implement these functions in Circle and Rectangle. Also write proper constructor(s) and other functions you
// think appropriate in the Circle and Rectangle class. Now create an array of 5 Shape2D pointers. Create 3 Circle
// and 2 Rectangles objects and place their addresses in that array. Use a loop to print area and perimeter of all
// shapes on this array.



#include <iostream>

using namespace std;

const double PI = 22.0 / 7.0;

class Shape2D {
   public:
    virtual double area() = 0;
    virtual double perimeter() = 0;
};

class Circle : public Shape2D {
    int radius;

   public:
    Circle(int r = 0) : radius(r) {}
    double area() { return PI * radius * radius; }
    double perimeter() { return 2 * PI * radius; }
};

class Rectangle : public Shape2D {
    int l;
    int b;

   public:
    Rectangle(int ll = 0, int bb = 0) : l(ll), b(bb) {}
    double area() { return l * b; }
    double perimeter() { return 2 * (l + b); }
};

int main() {
    Shape2D* sarr[5];
    sarr[0] = new Circle(2);
    sarr[1] = new Circle(4);
    sarr[2] = new Circle(6);
    sarr[3] = new Rectangle(2, 4);
    sarr[4] = new Rectangle(4, 6);

    for (int i = 0; i < 5; i++) {
        if (i < 3)
            cout << "Circle #" << i + 1 << " : ";
        else
            cout << "Rectangle #" << i - 2 << " : ";
        cout << "area : " << sarr[i]->area()
             << " ; perimeter : " << sarr[i]->perimeter() << endl;
    }
}
