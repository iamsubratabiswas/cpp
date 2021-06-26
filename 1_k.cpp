#include <iostream>
using namespace  std; 
void printIt(const int& x)
{
    std::cout << x<<" ";
}
 
int main()
{
    int a{ 1 };
    printIt(a); // non-const l-value
 
    const int b{ 2 };
    printIt(b); // const l-value
 
    printIt(3); // literal r-value
 
    printIt(2+b); // expression r-value
 
    return 0;
}


