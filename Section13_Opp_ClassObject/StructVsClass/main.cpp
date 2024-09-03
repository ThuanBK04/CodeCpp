/*

Struct vs classes:
- In addition to define a class we can declare a struct
- struct comes from the C programming language
- Essentially the same as a class expect
+ members are public by default

Some general guidelines:
- struct
+ Use struct for passive objects with public access
+ don't declare methods in struct
- class:
+ Use class for active objects with private access
+ Implement getters/setters as needed
+ Implement member methods as needed

*/

#include <iostream>

using namespace std;

int main()
{
	cout << "Default Template!" << endl; 
	return 0;
}
