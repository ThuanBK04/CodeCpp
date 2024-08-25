#include <iostream>

using namespace std;

/*
When to use pointers vs. references parameters
Pass-by-value:
When the function does not modify the actual parameter, and
the parameter is small and efficient to copy like simple type
*/

/*
Pass-by-reference using by pointer
when the function does modify the actual paramter
and the paramter is expensive to copy and it's ok to the pointer is allowed a nullptr value
*/

/*
Pass-by-reference using a reference
when the function does modify the actual paramter
and the paramter is expensive to copy
The parameter will never be nullptr
*/

int main()
{
	cout << "Default Template!" << endl; 
	return 0;
}
