// Classes and Objects
// Write a class IntArray for one dimensional integer array. Implement the necessary constructor, copy constructor,
// and destructor (if necessary) in this class. Implement other member functions to perform operations, such adding
// two arrays, reversing an array, sorting an array etc. Create an IntArray object having elements 1, 2 and 3 in it.
// Print its elements. Now, create another IntArray object which is an exact copy of the previous object. Print its
// elements. Now, reverse the elements of the last object. Finally print elements of both the objects


#include <iostream>

using namespace std;

// For array index out of bounds
class ArrayIndexOutOfBounds {};

class IntArray {
    int* arr;
    int size;

   public:
    IntArray(int size);
    IntArray(int size, int* arr);
    IntArray(const IntArray& ia);
    ~IntArray() { delete arr; }

    int& operator[](int i);
    IntArray add(const IntArray& ia);
    void reverse();
    void sort();
    void show();
};

// ++++++++++ Member functions of IntArray ++++++++++ //

// constructors
IntArray::IntArray(int size = 0) {
    this->size = size;
    arr = new int[size];
}

IntArray::IntArray(int size, int* arr) {
    this->size = size;
    this->arr = new int[size];
    for (int i = 0; i < size; i++) this->arr[i] = arr[i];
}

IntArray::IntArray(const IntArray& ia) {
    size = ia.size;
    arr = new int[size];
    for (int i = 0; i < size; i++) arr[i] = ia.arr[i];
}

// public memeber functions
int& IntArray::operator[](int i) {
    if (i < 0 || i >= size) {
        cout << "Index " << i << " is out of range for size " << size << endl;
        throw ArrayIndexOutOfBounds();
    }
    return arr[i];
}

IntArray IntArray::add(const IntArray& ia) {
    IntArray temp = IntArray(max(size, ia.size));
    for (int i = 0; i < size; i++) temp[i] = arr[i];
    for (int i = 0; i < ia.size; i++) temp[i] += ia.arr[i];
    return temp;
}

void IntArray::reverse() {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

// Using insertion sort to sort the array
void IntArray::sort() {
    for (int i = 1; i < size; i++) {
        for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--) {
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
        }
    }
}

void IntArray::show() {
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;
}

// ++++++++++ ++++++++++ ++++++++++ ++++++++++ ++++++++++ //

int main() {
    int arr[] = {1, 2, 3};
    IntArray obj1(3, arr);
    cout << "Obj1 : ";
    obj1.show();
    IntArray obj2(obj1);
    cout << "Obj2 : ";
    obj2.show();
    obj2.reverse();
    cout << "obj2.reverse() called" << endl;
    cout << "Obj1 : ";
    obj1.show();
    cout << "Obj2 : ";
    obj2.show();
    obj2.sort();
    cout << "obj2.sort() called" << endl;
    cout << "Obj2 : ";
    obj2.show();
}
