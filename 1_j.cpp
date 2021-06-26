#include <iostream>

using namespace std;

int main()
{
  int x = 10;
 
  // ref is a reference to x.
  int& ref = x;
 
  // Value of x is now changed to 20
  ref = 20;
  cout << "x = " << x << endl ;
 
  // Value of x is now changed to 30
  x = 30;
  cout << "ref = " << ref << endl ;
 
  return 0;
}
/*l) Applications :  
1.	Modify the passed parameters in a function: If a function receives a reference to a variable, it can modify the value of the variable. 
2. Avoiding a copy of large structures: Imagine a function that has to receive a large object. If we pass it without reference, a new copy of it is created which causes wastage of CPU time and memory. We can use references to avoid this.
3. In For Each Loops to modify all objects : We can use references in for each loops to modify all elements*/
