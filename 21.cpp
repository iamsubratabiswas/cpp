#include <iostream>

using namespace std;

class Vector {
    double* arr;
    int size;

   public:
    // Defining constructors
    Vector() {
        arr = NULL;
        size = 0;
    }

    Vector(int size) {
        this->size = size;
        arr = new double[size];
    }

    Vector(int size, double* a) {
        this->size = size;
         arr = new double[size];
        for (int i = 0; i < size; i++) {
            arr[i] = a[i];
        }
    }
    // Copy constructor
    Vector(const Vector& v) {
        size = v.size;
        arr = new double[size];
        for (int i = 0; i < size; i++) {
            arr[i] = v.arr[i];
        }
    }

    int getSize() { return size; }
    Vector add(const Vector& v);
    Vector sub(const Vector& v);
    bool equals(const Vector& v);
    double magnitude() const;
    bool lessThan(const Vector& v);
    bool greaterThan(const Vector& v);
    void show();
};

// ++++++++++ Member functions of Vector ++++++++++ //

Vector Vector::add(const Vector& v) {
    Vector temp(max(size, v.size));
    for (int i = 0; i < size; i++) temp.arr[i] += arr[i];
    for (int i = 0; i < v.size; i++) temp.arr[i] += v.arr[i];
    return temp;
}

Vector Vector::sub(const Vector& v) {
    Vector temp(max(size, v.size));
    for (int i = 0; i < size; i++) temp.arr[i] += arr[i];
    for (int i = 0; i < v.size; i++) temp.arr[i] -= v.arr[i];
    return temp;
}

bool Vector::equals(const Vector& v) {
    if (size != v.size) return false;
    for (int i = 0; i < size; i++)
        if (arr[i] != v.arr[i]) return false;
    return true;
}

double Vector::magnitude() const {
    double mag = 0;
    for (int i = 0; i < size; i++)
        mag += (arr[i]*arr[i]);
    return mag;
}

bool Vector::lessThan(const Vector& v) {
    if (magnitude() < v.magnitude()) return true;
    return false;
}

bool Vector::greaterThan(const Vector& v) {
    if (magnitude() > v.magnitude()) return true;
    return false;
}

void Vector::show() {
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << endl;
}

// ++++++++++ ++++++++++ ++++++++++ ++++++++++ ++++++++++ //

int main() {
    double arr1[] = {1, 2, 3, 4 , 5};
    double arr2[] = {4, 8, 9, 2};
    Vector v1(5, arr1), v2(4, arr2);
    cout << "v1 : ";
    v1.show();
    cout << "v2 : ";
    v2.show();
    Vector v3 = v1.add(v2);
    cout << "v1 + v2 = v3 : ";
    v3.show();
    Vector v4 = v1.sub(v2);
    cout << "v1 - v2 = v4 : ";
    v4.show();
    cout << "v3 == v4 : " << v3.equals(v4) << endl;
    cout << "v3 < v4 : " << v3.lessThan(v4) << endl;
    cout << "v3 > v4 : " << v3.greaterThan(v4) << endl;
}

