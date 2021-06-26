#include <iostream>

using namespace std;

int main() {
    cout << "Celsius --> Farenheit" << endl;
    for (int c = 0; c <= 100; c++) {
        float f = (float)c * (9.0/5.0) + 32.0;
        cout << c << " --> " << f << endl; 
    }
}
