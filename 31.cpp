// Operator Overloading
// Design a class Complex that includes all the necessary functions and operators like =, +, -, *, /.

#include <cmath>
#include <iostream>

using namespace std;

class Complex {
    double real;
    double img;

   public:
    Complex() {
        real = 0;
        img = 0;
    }
    Complex(double real, double img) {
        this->real = real;
        this->img = img;
    }

    void setReal(double real) { this->real = real; }
    void setImg(double img) { this->img = img; }
    double getReal() { return real; }
    double getImg() { return img; }

    void disp() { 
        if (real != 0) cout << real;
        if (real!= 0 && img>0) cout << " + ";
        if (real!= 0 && img<0) cout << " - ";
        if (img > 0) cout << img << "i"; 
        if (img < 0) cout << -img << "i";
        if (real == 0 && img == 0) cout << "0";
     }

    Complex conjugate() const { return Complex(real, -img); }
    double modulus() const { return sqrt(real * real + img * img); }

    Complex operator-() { return Complex(-real, -img); }

    Complex operator+(double d) { return Complex(real + d, img); }
    Complex operator+(const Complex& c) {
        return Complex(real + c.real, img + c.img);
    }

    Complex operator-(double d) { return Complex(real - d, img); }
    Complex operator-(const Complex& c) {
        return Complex(real - c.real, img - c.img);
    }

    Complex operator*(double d) { return Complex(real * d, img * d); }
    Complex operator*(const Complex& c) {
        return Complex((real * c.real) - (img * c.img),
                       (real * c.img) + (img * c.real));
    }

    Complex operator/(double d) { return Complex(real / d, img / d); }
    Complex operator/(const Complex& c) {
        return (*this * c.conjugate()) / (c.modulus() * c.modulus());
    }
};

int main() {
    Complex c1(3, 2), c2(4, -3);
    Complex c3 = c1 + c2;
    Complex c4 = c1 - c2;
    Complex c5 = c1 * c2;
    Complex c6 = c1 / c2;
    cout << "c1 = ";
    c1.disp();
    cout << "\nc2 = ";
    c2.disp();
    cout << "\nc1 + c2 = ";
    c3.disp();
    cout << "\nc1 - c2 = ";
    c4.disp();
    cout << "\nc1 * c2 = ";
    c5.disp();
    cout << "\nc1 / c2 = ";
    c6.disp();
    cout << endl;
}
