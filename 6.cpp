// Constants
//  Write a program that defines a constant PI and takes radius of a circle from keyboard and prints area of that
// circle.

#include <iostream>

using namespace std;

int main() {
    const float PI = 22.0/7.0;
    cout << "Enter the radius of the circle : ";
    int radius;
    cin >> radius;
    float area = PI*radius*radius;
    cout << "Area of the circle = " << area << endl;
}
