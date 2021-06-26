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
