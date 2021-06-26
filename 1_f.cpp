// The use of scope resolution operator (::)


 #include <iostream>

using namespace std;
int a=4;
int main()
{
int a=3;
cout<<a<<::a;
a=2;
cout<<a<<::a;
} 