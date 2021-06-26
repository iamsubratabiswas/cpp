// Inheritance
// Implement the Shape hierarchy as shown in the figure. Each TwoDShape should contain function getArea to
// calculate the area of two-dimensional shape. Each ThreeDShape should have member functions getArea and
// getVolume to calculate the surface area and volume of the three-dimensional shape respectively. Create a
// program that uses Vector of Shape pointers to objects of each concrete class in the hierarchy. Now write a
// program that processes all the shapes in the Vector such that if the shape is a TwoDShape it prints name of shape
// and its area while it prints name of shape, its area and volume if the shape is a ThreeDShape.

// (Cir:cle,Train:gle,Ellip:se) ---> TwoDSh ----Shape --- ThreeDSh <--- (Shape:re,Cu:be)
//                              ape                                 ape


#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

const double PI = 22.0 / 7.0;

class Shape {
   public:
    virtual void printDetails() = 0;
};

class TwoDShape : public Shape {
   public:
    virtual double getArea() = 0;
    virtual void printDetails() = 0;
};

class ThreeDShape : public Shape {
   public:
    virtual double getArea() = 0;
    virtual double getVolume() = 0;
    virtual void printDetails() = 0;
};

class Circle : public TwoDShape {
    double radius;

   public:
    Circle(double r = 0) : radius(r) {}

    double getArea() { return PI * radius * radius; }

    void printDetails() {
        cout << "Circle [Area : " << getArea() << "]" << endl;
    }
};

class Triangle : public TwoDShape {
    double a, b, c;

   public:
    Triangle(double a = 0, double b = 0, double c = 0) {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    double getArea() {
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    void printDetails() {
        cout << "Triangle [Area: " << getArea() << "]" << endl;
    }
};

class Ellipse : public TwoDShape {
    double a, b;

   public:
    Ellipse(double a = 0, double b = 0) {
        this->a = a;
        this->b = b;
    }

    double getArea() { return PI * a * b; }
    void printDetails() {
        cout << "Ellipse [Area : " << getArea() << "]" << endl;
    }
};

class Sphere : public ThreeDShape {
    double radius;

   public:
    Sphere(double r = 0) : radius(r) {}

    double getArea() { return 4 * PI * radius * radius; }

    double getVolume() { return (4.0 / 3.0) * PI * radius * radius * radius; }

    void printDetails() {
        cout << "Sphere [Surface area : " << getArea()
             << ", Volume : " << getVolume() << "]" << endl;
    }
};

class Cube : public ThreeDShape {
    double a;

   public:
    Cube(double a = 0) { this->a = a; }

    double getArea() { return 6 * a * a; }
    double getVolume() { return a * a * a; }

    void printDetails() {
        cout << "Cube [Surface area : " << getArea()
             << ", Volume : " << getVolume() << "]" << endl;
    }
};

int main() {
    vector<Shape *> s(5); 
    s[0] = new Circle(2);
    s[1] = new Triangle(4,5,6);
    s[2] = new Ellipse(7,8);
    s[3] = new Sphere(9);
    s[4] = new Cube(10);
    for (int i = 0; i < s.size(); i++) {
        s[i]->printDetails();
    }
}
