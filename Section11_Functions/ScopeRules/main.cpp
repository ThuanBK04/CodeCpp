/*
 * Local or block scope
 * 
 * Identifiers declared in a block {}
 * Function parameters have block scope
 * Only visible within the block {} where declared
 * Function local variables are only active while the function is executing
 * Local variables are not preserved between function calls
 * With nested blocks inner blocks can 'see' but outer blocks cannot 'see'
 * 
 * Static local variables
 * Declared with static qualifier
 *  static int value {10};
 * Value is preserved between function calls
 * Only initialized the first time the function is called(diff normal local variable-reinitialized everytime)
 * This variable retains its previous value
 * 
 * Global scope
 * Identifier declared outside any function or class
 * Visible to all parts of the program after the global identifier has been declared
 * Global constans are OK
 * Best practice - don't use global variables - any piece of code could change it
 *
 * 
 * 
 * 
 * ==>
 * ==> Rule: look local first then look out then look out then look out ... until hit global scope
 * ==>
 * 
 * 
 */

#include <iostream>

using namespace std;

int main()
{
	cout << "Default Template!" << endl; 
	return 0;
}
