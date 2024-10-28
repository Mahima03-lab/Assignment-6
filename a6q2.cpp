#include<iostream>
using namespace std;
struct foo{
foo(){cout << "foo()\n" ;}
~foo(){cout <<"~foo()\n";}
int i {5};
};
struct obj{
const foo& getFoo(){return my_foo;};
foo my_foo;
};
int main()
{
obj *o = new obj();
const foo& val = o->getFoo();
cout << "val.i=" << val.i << std::endl;
delete o;
cout << "val.i=" << val.i << std::endl;
}
/*  OUTPUT
    foo()
    val.i=5
    ~foo()
    val.i=15494920
    Here the foo struct has a default constructor (foo()) that prints "foo()" and a destructor (~foo()) that prints "~foo()" and integer member i initialized to 5.
    The obj struct contains a member my_foo of type foo and a method getFoo() which returns constant reference to my_foo.
    obj *o = new obj();--here o is pointer to obj type and new keyword dynamically allocates memory for an obj instance .
    This allocation creates the obj instance and initializing its members.Again obj contains member my_foo of type foo so it invokes the default constructor foo and prints foo().
    const foo& val = o->getFoo(); -- which means val is now a constant reference to my_foo inside obj.
    Hence val.i prints 5.
    The delete o; --- deletes the obj instance o and invokes the destructor of constructor foo ,as a result ~foo() is printed.
    Now deleting o we lost the memory of my_foo as a result val.i gives garbage value.
    */
