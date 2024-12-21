/*

The final specifier:
- C++11 provides the final specifier
+ When used at the class level
	Prevents a class from being derived from
+ When used at the method level
	Prevents virtual method from being overridden in derived classes
Syntax: final class
class My_class final
{
	...
};
class Derived final: public Base
{
	...
};

Syntax: final method
class A
{
public:
	virtual void do_something();
}
class B: public A
{
	virtual void do_something() final; // prevent futher overriding
}
class C:public B
{
	virtual void do_something(); // Compiler error - Can't override
}
Explain:
The base class a declares the function do something as virtual.
Class b is derived from a and it overrides do something but it also marks it as final.
So do something can no longer be overridden further down in the hierarchy.
Notice that if class c tries to override do something, the compiler generates an error.

*/


#include <iostream>

using namespace std;

int main()
{
	cout << "Default Template!" << endl; 
	return 0;
}
