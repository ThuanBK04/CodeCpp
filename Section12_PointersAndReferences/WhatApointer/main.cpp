/*

What is a Pointer ?
    A variable:
     * Whose value is an address
    What can be at the address ?
     * Another variable
     * A function
    Pointers point to variables or functions ?
     * If x is an integer variable and its value is 10, then I can declare a pointer that points to it
    To use the data that the pointer is pointing to you must know its type

Why use Pointers ?
    Can't I just use the variable or function itself ?
    Yes, but not always
     * Inside functions, pointers can be used to access data that are defined outside the function
       Those variables may not be in scope so you can't access them by their name
     * Pointers can be used to operate on arrays very efficiently
     * We can allocate memory dynamically on the heap or free store
        This memory doesn't even have a variable name
        The only way to get to it is via a pointer
     * With OO. Pointers are how polymorphism works
     * Can access specific address in memory: useful in embedded and systems applications
*/

#include <iostream>

using namespace std;

int main()
{
	cout << "Default Template!" << endl; 
	return 0;
}
