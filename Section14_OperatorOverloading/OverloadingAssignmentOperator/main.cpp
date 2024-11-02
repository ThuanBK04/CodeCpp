/*

You can choose to overload the move assignment operator
+ C++ will use the copy assignment operator if necessary
Mystring s1;
// Notice that the mystring object initialized to frank must be constructed.
// And once it's constructed, it has no name, it's a temporary object. So it's an r-value.
// That means that when we assign it to s1, the move assignment
// operator will be called since we're providing an r-value reference.
s1 = Mystring {"Frank"}; // move assignment
If we have raw pointer we should overload the move assignment operator for efficiency

*/

/*

Syntax:
// The right-hand side object reference can't be const
// since we'll be modifying that object when we move the data.
Type &Type::operator=(Type &&rhs)
Mystring &Mystring::operator=(Mystring &&rhs);
s1 = Mystring{"Joe"}; // move operator= called
s1 = "Frank"; // move operator= called

Mystring &Mystring::operator=(Mystring &&rhs)
{
	if (this == &rhs) //self assignment
		return *this;

	delete [] str; //deallocate current storage
	str = rhs.str; //steal the pointer
	rhs.str = nullptr; // null out the rhs object
	return *this;
}

*/

#include <iostream>
#include <vector>
#include "Mystring.h"

using namespace std;

int main() {
    Mystring a{"Hello"};                // Overloaded constructor
    a = Mystring{"Hola"};               // Overloaded constructor then move assignment
    a = "Bonjour";

    return 0;
}
