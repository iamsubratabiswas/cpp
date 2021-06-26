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
