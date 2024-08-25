#include <iostream>

using namespace std;

/*
    Uninitialized pointers
*/
int *int_ptr; // pointing anywhere
*int_ptr = 100; // Hopefully a crash

/*
    Dangling pointer
     * Pointer that is pointing to released memory
     * * For example: 2pointers point to the same data
     * * 1 pointer releases the data with delete
     * * The other pointer accesses the release data

     * Pointer that points to memory that is invalid
     * * We saw this when we returned a pointer to a function local variable that are no longer valid
     * * when function is terminated
*/

/*
    Not checking if new failed
     * If new fails a exception is thrown
     * We can use exception handling to catch exceptions
     * Dereferencing a null pointer will cause your program to crash
*/

/*
    Leaking memory:
     * Forgetting to release allocated memory with delete
     * If you lose your pointer to the storage allocated on the heap you have not way to get to that storage again
     * The memory is orphaned or leaked
     * One of the most common pointer problems
*/

int main()
{
	cout << "Default Template!" << endl; 
	return 0;
}
