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
        if (real != 0) {
            cout << real;
            if (img != 0) cout << " + ";
        }
        if (img != 0) cout << img << "i";
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

class Quadratic {
    double a;  // coeff. of x^2
    double b;  // coeff. of x
    double c;  // constant

   public:
    Quadratic(double c = 0, double b = 0, double a = 0) {
        this->c = c;
        this->b = b;
        this->a = a;
    }

    void setA(double a) { this->a = a; }
    void setB(double b) { this->b = b; }
    void setC(double c) { this->c = c; }

    double getA() { return a; }
    double getB() { return b; }
    double getC() { return c; }

    Quadratic operator+(const Quadratic& q) {
        return Quadratic(c + q.c, b + q.b, a + q.a);
    }

    friend ostream& operator<<(ostream& cout, const Quadratic& q);
    friend istream& operator>>(istream& cin, Quadratic& q);

    double value(double x) { return x * x * a + x * b + c; }

    void computeRoots(Complex& root1, Complex& root2) {
        double D = b * b - 4 * a * c;
        Complex d;
        if (D >= 0) {
            d.setReal(sqrt(D));
            d.setImg(0);
        } else {
            d.setReal(0);
            d.setImg(sqrt(-D));
        }
        root1 = (d - b) / (2 * a);
        root2 = (-d - b) / (2 * a);
    }
};

// ++++++++++ friend functions of Quadratic ++++++++++ //

ostream& operator<<(ostream& cout, const Quadratic& q) {
    cout << q.a << ".x^2 + " << q.b << ".x + " << q.c;
    return cout;
}

istream& operator>>(istream& cin, Quadratic& q) {
    cout << "Form : ax^2 + bx + c" << endl;
    cout << "Enter a :";
    cin >> q.a;
    cout << "Enter b :";
    cin >> q.b;
    cout << "Enter c :";
    cin >> q.c;
    return cin;
}

// ++++++++++ ++++++++++ ++++++++++ ++++++++++ ++++++++++ //

int main() {
    Quadratic e1, e2, e3;
    cout << "Enter first polynomial : " << endl;
    cin >> e1;
    cout << "Enter second polynomial : " << endl;
    cin >> e2;
    e3 = e1 + e2;
    cout << "e1 + e2 = " << e3 << endl;
    double x;
    cout << "Enter x to calculate value of e1(x) : ";
    cin >> x;
    cout << "e1(" << x << ") = " << e1.value(x) << endl;
    Complex root1, root2;
    e1.computeRoots(root1, root2);
    cout << "Roots of e1(x) = 0 are : x = "; 
    root1.disp();
    cout << " and x = ";
    root2.disp(); 
    cout << endl;
}
