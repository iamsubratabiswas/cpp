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

    void disp() const {
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

    friend ostream& operator<<(ostream& cout, const Complex& c) {
        c.disp();
        return cout;
    }
};

class StackOverFlow{};
class StackUnderFlow{};
class NegativeSize{};

template <class T>
class Stack {
    T* buffer;
    int top;
    int size;
   public : 
    Stack(int size = 0) {
        if (size < 0) throw NegativeSize();
        this->size = size;
        buffer = new T[size];
        top = -1;
    }
    
    void push(T data) {
        if (top == size - 1) throw StackOverFlow();
        buffer[++top] = data;
    }

    T pop() {    
        if (top == -1) throw StackUnderFlow();
        return buffer[top--];
    }

    void disp() {
        for (int i = top; i >= 0; i--) cout << buffer[i] << ",  ";
        cout << endl;
    }
};

int main() {
    Stack<int> s(10);
    for (int i = 0; i < 10; i++) s.push(i);
    cout << "Popped from int stack : " << s.pop() << endl;
    cout << "Popped from int stack : " << s.pop() << endl;
    cout << "Popped from int stack : " << s.pop() << endl;

    Stack<Complex> s1(10);
    for (int i = 0; i < 10; i++) s1.push(Complex(i, i-2));
    cout << "Popped from Complex stack : " << s1.pop() << endl;
    cout << "Popped from Complex stack : " << s1.pop() << endl;
    cout << "Popped from Complex stack : " << s1.pop() << endl;

    cout << "int Stack : ";
    s.disp();
    cout << "Complex Stack : ";
    s1.disp();
}
