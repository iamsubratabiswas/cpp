// Create a factorial table using cout as follows:
// 1! = 1
// 2! = 2
// 3! = 6
// …
// 6! = 720




#include <iostream>

using namespace std;

int main() {
    for (int i = 1; i <= 10; i++) {
        int fact = 1;
        for (int j = 1; j <= i; j++)
            fact *= j;
        cout << i << "! = " << fact << endl;
    }
}
