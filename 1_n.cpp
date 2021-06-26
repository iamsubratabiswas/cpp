#include <iostream>

using namespace std;

inline int min(int x, int y)
{
return (x<y?x:y);
}

int main()
{
int x,y;
cout<<"enter any two no = ";
cin>>x>>y;
cout<<"min no is = "<<min(x,y);
}