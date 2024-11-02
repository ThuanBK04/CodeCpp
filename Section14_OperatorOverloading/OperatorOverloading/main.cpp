/*

Operator overloading:
- Copy assignment operator (=)
- C++ provides a default assignment operator used for assigning one object to another
Mystring s1 {"Frank"};
Mystring s2 = s1; // not assignment
				  // same as Mystring s2{s1};

s2 = s1; // assignment
- Deafault is memberwise assignment (sahllow copy)
- If we have raw pointer data member we must deep copy

- Overloading the copy assignment operator (deep coppy)
		Type &Type::operator=(const Type &rhs);
		Mystring &mystring::operator=(const Mystring &rhs);
		s2 = s1; // We write this
		s2.operator=(s1); // operator=method is called
*/

/*

- Remember, the object on the left-hand side of an assignment statement
is referred to by the this pointer.
- The object on the right-hand side is being passed into the method.
and named the right-hand side object RHS for right-hand side.
- Overloading the copy asignment operator (deep copy):
Mystring &Mystring::operator=(const Mystring &rhs)
{
	if (this == &rhs)
	{
		return *this;
	}


	// The left-hand side object or this object will be overwritten.
	// So we need to de-allocate anything it refers to on the heap.
	// Then we have to allocate space
	// in the left-hand side object for the right-hand side object's data,
	// and then we finally copy the data over to the left side from the right side.
	delete [] str;
	str = new char[std::strlen(rhs.str) + 1];
	std::strcpy(str, rhs.str);

	return *this;
}

Analysis: Overloading the copy assignment operator - step for deep coppy
+ Check for self assignment
	if (this == &rhs)   // p1 = p1;
		return *this; // return current object
+ Deallocate storage for this->str since we are overwriting it
Need to de-allocate the storage. Otherwise when we copy the new data over,
we'll orphan this memory and end up with a memory leak.
	delete [] str;
+ Allocate storage for the deep copy:
	str = new char[std::strlen(rhs.str) + 1];
+ Perform the copy:
We can perform the copy by copying over one character at a time until we see the null character.
But since we're using a c-style string, we can simply call the string library method stood string copy
	std::strcpy(str, rhs.str);
+ Return the current by reference to allow chain assignment
	return *this;

*/

#include <iostream>
#include "Mystring.h"

using namespace std;

int main()
{
    Mystring a{"Hello"}; // overloaded constructor
    Mystring b; // no-args constructor
    b = a; // copy assignment
    b = "This is a test"; // b.operator=("This is a test")

    return 0;
}
