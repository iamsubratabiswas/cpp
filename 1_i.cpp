// Constants and Pointers. (Also find some area of usage)


#include <iostream>

using namespace std;
int main()
{
int num,*pnum;
pnum=&num;
cout<<"enter the no = ";
cin>>num;
cout<<"the no entered is = ";
cout<<*pnum;
}
/* use of pointers-
1.	 Pointers are used with data structures. They are useful for representing two-dimensional and multi-dimensional
arrays.
2.	An array, of any type can be accessed with the help of pointers, without considering its subscript range.
3.	Pointers are used for file handling.*/