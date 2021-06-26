#include <string.h>
#include <cmath>
#include <iostream>

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
        if (real != 0) std::cout << real;
        if (real != 0 && img > 0) std::cout << " + ";
        if (real != 0 && img < 0) std::cout << " - ";
        if (img > 0) std::cout << img << "i";
        if (img < 0) std::cout << -img << "i";
        if (real == 0 && img == 0) std::cout << "0";
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

    bool operator>(const Complex& c) {
        if (modulus() > c.modulus()) return true;
        return false;
    }
};

template <class T>
T max(T t1, T t2) {
    if (t1 > t2) return t1;
    return t2;
}

char* max(char* s1, char* s2) {
    if (strcmp(s1, s2) > 0) return s1;
    return s2;
}

int main() {
    int a = 10, b = 20;
    std::cout << max(a, b) << std::endl;
    Complex c1(1, 2), c2(3, 4);
    max(c1, c2).disp();
    std::cout << std::endl;
    char str1[] = "str1";
    char str2[] = "str2";
    std::cout << max(str1, str2) << std::endl;
}
