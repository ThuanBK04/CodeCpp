/*

- Friend:
+ A function or class that has access to private class member
+ And, that function or class is not member of the class it is accessing

- Function:
+ Can be regular non-member functions
+ Can be member methods of another class

- Class
+ Another class can have access to private class members

*/

/*

- Friendship must be granted not taken
+ Declared explicitly in the class that is granting friendship
+ Declared in the function prototype with the keyword friend

- Friendship is not symmetric
+ Must be explicitly granted
If A is a friend of B, that doesn't mean B is not a friend of A, this must be explicitly granted.

- Friendship is not transitive
+ Must be explicitly granted
If A is a friend of B and B is a friend of C, then A is not a friend of C unless specifically granted.

*/

/*

---> Non-member function <---
class Player
{
	friend void display_player(Player &p);
	string name;
	int health;
	int xp;
public:
	...
};

void display_player(Player &p)
{
	cout << p.name << endl;
}
display_player may also change private data memebers

*/

/*

---> member function of another class <---
class Player
{
	friend void Otherclass::display_player(Player &p);
	string name;
	int health;
	int xp;
public:
	...
};

class Other_class
{
...
public:
	void display_player (Player &p)
	{
		cout << p.name << endl;
		...
	}
}

*/

/*

Another class as a friend

class Player
{
	friend class Other_class;
	string name;
	int health;
	int xp;
public:
	...
};

*/

#include <iostream>

using namespace std;

int main()
{
	cout << "Default Template!" << endl; 
	return 0;
}
