#include <iostream>

using namespace std;

void prnsqr(int i)
{
cout<<"sqr is = "<<i*i;
}

void prnsqr(float f)
{
cout<<"sqr is = "<<f*f;
}
int main()
{
int x;
float y;
cout<<"enter any no = ";
cin>>x>>y;
prnsqr(x);
prnsqr(y);
}