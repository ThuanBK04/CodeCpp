/*

Operator Overloading
- Using traditional operators such as +, =, *, etc. with user-defined types
- Allows user defined types to behave similar to built-in types
- Can make code more readable and writable
- Not done automatically (except for the assignment operator)
They must be explicitly defined

- Suppose we have a number class that models any number
+ Using functions:
Number result = multiply(add(a, b), divide(c, d));
+ Using member methods:
Number result = (a.add(b)).multiply(c.divide(d));
-> These statements are very unreadable and very difficult to write

- What operators can be overloaded ?
+ The majority of C++'s operators can be overloaded
+ The following operators cannot be overload:
    ::		:?		.*		sizeof

- Some basic rules:
+ Precedence and associativity cannot be changed
+ 'arity' cannot be changed (i.e can't make the division operator unary)
+ Can't overload operators for primitive type (e.g int, double, etc)
+ Can't create new operators
+ [], (), ->, and the assignment operator (=) must be declared as member methods
+ Other operators can be declared as member methods or global functions

*/

#include <iostream>
#include "Mystring.h"

using namespace std;

int main()
{
	Mystring empty; // no-args constructor
    Mystring larry("Larry"); // overloaded constructor
    Mystring stooge{larry}; // copy constructor

    empty.display();
    larry.display();
    stooge.display();

	return 0;
}
