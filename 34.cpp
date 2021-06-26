// Operator Overloading
//  Design and implement class(es) to support the following main program.
// int main() {
// IntArray i(10);
// for(int k = 0; k < 10; k++)
// i[k] = k;
// cout << i;
// return 0;
// }

#include <iostream>

using namespace std;

// For array index out of bounds
class ArrayIndexOutOfBounds {};

class IntArray {
    int* arr;
    int size;

   public:
    IntArray() {}
    IntArray(int size) {
        this->size = size;
        arr = new int[size];
    }
    ~IntArray() { delete arr; }

    int& operator[](int i) {
        if (i < 0 || i >= size) {
            cout << "Index " << i << " is out of range for size " << size
                 << endl;
            throw ArrayIndexOutOfBounds();
        }
        return arr[i];
    }

    friend ostream& operator<<(ostream& cout, const IntArray& ia) {
        for (int i = 0; i < ia.size; i++) cout << ia.arr[i] << " ";
        return cout;
    }
};

int main() {
    IntArray i(10);
    for (int k = 0; k < 10; k++) i[k] = k;
    cout << i;
    return 0;
}
