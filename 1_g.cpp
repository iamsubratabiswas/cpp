//Constants:


 #include <iostream>

using namespace std;
int main()
{
const int b=5;
int a=10;
cout<<b<<" "<<a;
a+=b;
cout<<a;
//b+=a;     //error:attempt to write to const object
cout<<b;
}