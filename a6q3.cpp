#include<iostream>
using namespace std;
 struct X 
{
  X(){cout << "default constructor\n";};
  X(X&& x){ cout << "move constructor\n";};
  X(const X& x){cout << "copy constructor\n";};
  const X& operator=(const X&){cout << "copy assignment\n"; return *this;};
  ~X(){cout << "Destructor\n";};
};
X foo(X x){
  return x;
}
int main()
{
  X obj;
  obj = foo(obj);
}
/*
  OUTPUT:
default constructor
copy constructor
move constructor
copy assignment
Destructor
Destructor
Destructor

  In main() first default constructor is invoked so it will print 'default constructor'.
  On the next line first copy constructor is invoked so it prints 'copy constructor',after that obj is moved with the help of move constructor and hence ptints'move constructor' 
  ,finally  'copy assignmet' is printed as the copy assignment is invoked.
  At last all the constructors are destroyed after exiting main(),since default constructor,copy constructor,move constructor are invoked so three of them will be destroyed so 'Destructor' is printed thrice.*/ 