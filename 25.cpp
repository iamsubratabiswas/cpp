// Classes and Objects
//  Write the definition for a class called Complex that has private floating point data members for storing real and
// imaginary parts. The class has the following public member functions:
// setReal() and setImg() to set the real and imaginary part respectively.
// getReal() and getImg() to get the real and imaginary part respectively.
// disp() to display complex number object
// sum() to sum two complex numbers & return a complex number
// Write main function to create three complex number objects. Set the value in two objects and call sum() to
// calculate sum and assign it in third object. Display all complex numbers.



#include <iostream>

using namespace std;

class Complex {
    float real;
    float img;

   public:
    Complex(float real = 0, float img = 0) {
        this->real = real;
        this->img = img;
    }

    void setReal(float real) { this->real = real; }

    void setImg(float img) { this->img = img; }

    float getReal() { return real; }

    float getImg() { return img; }

    void disp() { cout << real << " + " << img << "i" << endl; }

    Complex sum(const Complex& c) {
        return Complex(real + c.real, img + c.img);
    }
};

int main() {
    Complex c1, c2;
    c1.setReal(1);
    c1.setImg(-2);
    c2.setReal(3);
    c2.setImg(4);
    Complex c3 = c1.sum(c2);
    c1.disp();
    c2.disp();
    c3.disp();
}
