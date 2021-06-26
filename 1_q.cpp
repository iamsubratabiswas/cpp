#include <iostream>

using namespace std;

float interest(float prn,int time,float rate=20)
{
return((prn*rate*time)/100);
}

int main()
{
float prn,r,si=0;
int t;
cout<<"enter the principle,rate,time of loan = ";
cin>>prn>>r>>t;
cout<<interest(prn,t,r)<<" ";
cout<<interest(prn,t);
}