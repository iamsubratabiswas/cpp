// Flexible Variable Declaration
//  Write a program to display Celsius to Fahrenheit conversion table using a for loop. Consider only 0˚ to 100˚
// Celsius. Declare variables when they are used for the first time.

#include <iostream>

using namespace std;

int main() {
    cout << "Celsius --> Farenheit" << endl;
    for (int c = 0; c <= 100; c++) {
        float f = (float)c * (9.0/5.0) + 32.0;
        cout << c << " --> " << f << endl; 
    }
}
