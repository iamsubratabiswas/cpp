// Operator Overloading
//  Design and implement class(es) to support the following code segment.
// Index in(4), out(10);
// int x = in;
// int y = in + out;
// in = 2;
// Integer i;
// i = in;


#include <iostream>

using namespace std;

class Index {
    int i;

   public:
    Index(int i = 0) { this->i = i; }
    operator int() { return i; }
    Index operator+(const Index& t) { return Index(i + t.i); }
    int getIndex() const { return i; }
};

class Integer {
    int i;

   public:
    Integer(int a = 0) : i(a) {}

    Integer(const Index& in) { i = in.getIndex(); }

    Integer operator++() { return Integer(++i); }

    Integer operator++(int) { return Integer(i++); }

    Integer operator+(const Integer& that) { return Integer(i + that.i); }

    operator int() { return i; }

    friend ostream& operator<<(ostream& cout, const Integer& ia) {
        return cout << ia.i << " ";
    }
};

int main() {
    Index in(4), out(10);
    int x = in;
    int y = in + out;
    in = 2;
    Integer i;
    i = in;
}
