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
