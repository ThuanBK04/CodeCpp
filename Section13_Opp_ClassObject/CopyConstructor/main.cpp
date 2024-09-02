/*

Copy Constructor:
- When objects are copied C++ must create a new object from an existing object
- When is a copy of an object made ?
+ passing object by value as a parameter
+ returning an object from a function by value
+ constructing one object based on another of the same class
- C++ must have a way of accomplishing this so it provides a compiler-defined copy constructor if you don't

*/

/*

Pass object by value:
void display_player (Player p)
{
	// p is a COPY of hero
	// use p
	// Destructor
}

*/

/*

Return object by value:
Player create_super_enemy()
{
	Player an_enemy {"Super Enemey", 1000, 1000};
	return an_enemy; // A COPY of an_enemy is returned
}

*/

/*

Constructor one object based on another:
Player create_super_enemy()
Player hero {"Hero", 100, 100};
Player another_hero{hero}; // a copy of hero is made

*/

/*

Copy constructor
If you don't provide your own way of copying objects by value then the compiler provides a default way of copying objects

Copies the values of each data member to the new object
- default memberwise copy

Perfectly fine in many cases

Beware if you have a pointer data member
- Pointer will be copied
- Not what it is pointing to
- Shallow vs. Deep copy - more in the next video

*/

/*

Best practice:
- Provide a copy constructor when your class has raw pointer members
- Provide the copy constructor with a const reference parameter
- Use STL classes as they already provide  copy constructors
- Avoid using raw pointer data members if possible

*/

/*

Declaring the copy constructor

Type::Type(const Type &source);
Example: Player::Player(const Player &source);

Why by reference and constant ?
+ If pass it in by value, then have to make a copy of it. That's the whole point of the copy constructor
We would defeat the purpose and end up with never ending recursive calls
+ As constant because the semantics of copying means that we're copying the source, we're not modifying it

Implementing the copy constructor
Type::Type(const Type &source)
{
	// code or initialization list to copy the object
}

Example:
Player::Player (const Player &source)
	: name{source.name}, health {source.health}, xp {source.xp}
{
}

*/

#include <iostream>

using namespace std;

class Player
{
private:
	string name;
	int health;
	int xp;
public:
	string get_name() {return name;}
	int get_health() {return health;}
	int get_xp() {return xp;}

	Player(string name_val = "None", int health_val = 0, int xp_val = 0);
	// Copy constructor
	Player (const Player &source);
	// Destructor
	~Player(){cout << "Destructor called for: " << name << endl;}
};

Player::Player(string name_val, int health_val, int xp_val)
	: name {name_val}, health {health_val}, xp {xp_val}
{
	cout << "Three-args constructor for: " + name << endl;
}

Player::Player(const Player &source)
//	:name{source.name}, health{source.health}, xp{source.xp}
	:Player{source.name, source.health, source.xp}
{
	cout << "Copy constructor - made copy of: " << source.name << endl;
}

void display_player(Player p)
{
	cout << "Name: " << p.get_name() << endl;
	cout << "Health: " << p.get_health() << endl;
	cout << "XP: " << p.get_xp() << endl;
}

int main()
{
	Player empty;
	Player frank{"Frank"};
	Player hero{"Hero", 100};
	Player villain{"Villain", 100, 55};

	return 0;
}
