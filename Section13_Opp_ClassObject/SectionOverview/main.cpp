/*

Two the main strengths of object orientation are encapsulation, information hiding

Classes and Object:
+ focus is on classes that model real-world domain entities
+ allows developers to think at a higher level of abstraction
+ used successfully in very large programs

Encapsulation:
+ objects contain data AND operations that work on that data
+ Abstract Data Type (ADT)

Information-hiding:
+ implementation-specific logic can be hidden
+ users of the class code to the interface since they don't need to know the implementation
+ more abstraction
+ easier to test, debug, maintain and extend

Reusability
+ easier to reuse classes in other application
+ faster developent
+ higher quality

Inheritance
+ can create new classes in term of existing classes
+ resuability
+ polymorphic classes

Polymorphism and more...

Classes:
+ blueprint from which objects are created
+ a user-defined data-type
+ has attributes (data)
+ has methods (functions)
+ can hide data and methods
+ provides a public interface

Examples class:
+ Account
+ Employee
+ std::vector
+ std::string

Objects:
+ created from a class
+ represents a specific instance of a class
+ can create its own identity
+ each can use the defined class methods

*/

#include <iostream>

using namespace std;

int main()
{
	cout << "Default Template!" << endl; 
	return 0;
}
