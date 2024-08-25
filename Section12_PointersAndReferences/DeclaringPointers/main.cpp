#include <iostream>

using namespace std;

// Like all variables, it don't initialize our varibales, they will contain garbage data
int *int_ptr; // int_ptr is an int pointer <-> a pointer to an integer
string *string_ptr; // string pointer <-> a pointer to a C++ string object

// If don't initialize a pointer variable, it will have garbage data which represents an address
// since that's what a pointer contains, so can think an unitialized pointer as pointing anywhere
// Initializing pointer variables is just like initializing non-pointer variables
// Initializing to zero or nullptr (C++ 11) represents address zero
int *int_ptr {nullptr}; // initialize the pointer variables to zero <-> the pointer to point nowhere
                        // That's very different from pointing anywhere

int main()
{
	cout << "Default Template!" << endl; 
	return 0;
}
