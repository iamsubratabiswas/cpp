#include <iostream>

using namespace std;

class Integer {
    int i;

   public:
    Integer(int a = 0) : i(a) {}

    Integer operator++() { return Integer(++i); }

    Integer operator++(int) { return Integer(i++); }

    Integer operator+(const Integer& that) { return Integer(i + that.i); }

    operator int() { return i; }

    friend ostream& operator<<(ostream& cout, const Integer& ia) {
        return cout << ia.i << " "; 
    }
};

int main() {
    Integer a = 4, b = a, c;
    c = a + b++;
    int i = a;
    cout << a << b << c;
    return 0;
}
