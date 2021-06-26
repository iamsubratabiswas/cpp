// Templates
//  Write a template function swap() that is capable of interchanging the values of two variables. Used this function
// to swap (i) two integers, (ii) two complex numbers (previous code may be reused). Now write a specialized
// template function for the class Stack (previous code may be reused). Also swap two stacks using this template
// function

#include <cmath>
#include <iostream>

using std::cout;


class StackOverFlow{};
class StackUnderFlow{};
class NegativeSize{};

class Stack {
    int* buffer;
    int top;
    int size;
   public : 
    Stack(int size = 0) {
        if (size < 0) throw NegativeSize();
        this->size = size;
        buffer = new int[size];
        top = -1;
    }

    Stack(const Stack& s) {
        size = s.size;
        top = s.top;
        buffer = new int[size];
        for (int i = 0; i <= top; i++) buffer[i] = s.buffer[i];
    }
    
    Stack copy() {
        Stack temp;
        temp.size = size;
        temp.top = top;
        temp.buffer = new int[size];
        for (int i = 0; i <= top; i++) temp.buffer[i] = buffer[i];
        return temp;
    }

    void push(int data) {
        if (top == size - 1) throw StackOverFlow();
        buffer[++top] = data;
    }

    int pop() {    
        if (top == -1) throw StackUnderFlow();
        return buffer[top--];
    }

    void disp() {
        for (int i = top; i >= 0; i--) cout << buffer[i] << " ";
        cout << "\n";
    }
};

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
void swap(T& t1, T& t2) {
    T temp = t1;
    t1 = t2;
    t2 = temp;
}

void swap(Stack& s1, Stack& s2) {
    Stack temp = s1;
    s1 = s2.copy();
    s2 = temp.copy();
}

int main() {
    int a = 10, b = 20;
    cout << "Before swap : " << a << " " << b << "\n";
    swap(a, b);
    cout << "After swap : " << a << " " << b << "\n";
    Complex c1(1, 2), c2(3, 4);
    cout << "Before swap : ";
    c1.disp();
    cout << " , ";
    c2.disp();
    cout << "\n";
    swap(c1, c2);
    cout << "After swap : ";
    c1.disp();
    cout << " , ";
    c2.disp();
    cout << "\n";

    Stack s1(5), s2(5);
    s1.push(1);
    s1.push(2);
    s2.push(3);
    s2.push(4);
    cout << "Before swap : \n";
    s1.disp();
    s2.disp();
    swap(s1, s2);
    cout << "After swap : \n";
    s1.disp();
    s2.disp();
}
