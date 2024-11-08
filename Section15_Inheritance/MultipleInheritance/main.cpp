/*

- A derived class inherits from two or more Base classes at the same time
- The Base classes may belong to unrelated class hierachies

Syntax:
class Department_Chair:
	public Faculty, public Administrator
{
}
- Some compelling use-cases
- Easily misused
- Can be very complex

*/

#include <iostream>

using namespace std;

int main()
{
	cout << "Default Template!" << endl; 
	return 0;
}
