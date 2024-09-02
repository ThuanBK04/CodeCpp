/*

So far, all data memeber values have been set in the constructor body
Constructor initialization list:
+ are more efficient
+ initialization list immediatedly follows the parameter list
+ initializes the data members as the objects is created
+ order of initialization is the order of declaration in the class

Note: "This" represents the current object

*/

/*

Example:
Previous way:
Player::Player()
{
	name = "None"; // assigment not initialization
	health = 0;
	xp = 0;
}

Better way:
Player::Player():name{"None"}, health{0}, xp{0}
{
}

*/

#include <iostream>

using namespace std;

int main()
{
	cout << "Default Template!" << endl; 
	return 0;
}
