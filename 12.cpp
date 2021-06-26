// Constants and pointers
// 12. Write a function Strcpy to copy one string to another with suitable formal parameters declarations. Following
// points must be considered.
// a) Source string must not get modified
// b) Target string is allowed to get modified
// c) The Pointers must be constant pointers.
//Use it to copy some strings.
#include <iostream>

using namespace std;

void Strcpy(const string& source, string& target) {
    target.clear();
    for (int i = 0; i < source.length(); i++) {
        target.push_back(source[i]);
        
    }
}
int main() {
    string a = "string a";
    string b = "string b";
    string c, d;
    Strcpy(a, c);
    Strcpy(b, d);
    cout << "a : " << a << endl;
    cout << "b : " << b << endl;
    cout << "c : " << c << endl;
    cout << "d : " << d << endl;
}
