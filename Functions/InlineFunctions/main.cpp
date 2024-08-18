/*
    Inline function:
     * Function calls have a certain amount of overhead
     * You saw what happens on the call stack
     * Sometimes we have simple functions and the function call overhead might be greater than
       the time spent executing the funtion.
       --> In cases such as these, we can suggest to the compiler to compile them 'inline'
           - avoid function call overhead
           - generate inline assembly code
           - faster. If you inline a function many times, then you're duplicating function code in
             many places and it could lead to larger binaries
           - could cause code bloat
     * Compilers optimizations are very sophisticated
     *  will likely inline even without your suggestion
*/ 

#include <iostream>

inline int add(int a, int b)
{
    return a + b;
}

using namespace std;

int main()
{
	cout << "Default Template!" << endl; 
	return 0;
}
