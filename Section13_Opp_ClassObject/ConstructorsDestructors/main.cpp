#include <iostream>

using namespace std;

/*
Constructor
- Special memeber method
- Invoked during object creation
- Useful for initialization
- Same name as the class
- No return type is specificed
- Can be overloaded
*/

/*
Destructor
- Special memeber method
- Same name as the class proceeded with a tilde (~)
- Invoked automatically when an object is destroyed
- No return type and no parameters
- Only 1 destructor is allowed per class - cannot be overloaded
- Useful to release memory and other resources
- Destructors are called in the order reverse order in which they were created
*/

/*
- If provide no constructors and no destructor, C++ automatically provide a default constructor and destructor that are empty
*/

/* Constructor Destructor
class Account
{
private:
	std::string name;
	double balance;
public:
	// Constructor
	Account();
	Account(std::string name, double balance);
	Account(std::string name);
	Account(double balance);
	// Destructor
	~Account();
}
 */

/*
How and when are contructors and destructors called

Ex1:
{
	Player slayer;
	Player frank {"Frank", 100, 4};
	// When block ends, these objects go out of scope
	// and their destructors will be called automatically
}

Ex2:
Player *enemy = new Player("Enemy", 1000, 0);
delete enemy; // destructor called
*/

#include <string>
using namespace std;

class Player
{
private:
	string name;
	int health;
	int xp;
public:
	void set_name(string name_val)
	{
		name = name_val;
	}

	// Overloaded constructors
	Player()
	{
		cout << "No args constructor called" << endl;
	}
	Player(string name)
	{
		cout << "String arg constructor called" << endl;
	}
	Player(string name, int health, int xp)
	{
		cout << "Three args constructor called" << endl;
	}
	~Player()
	{
		cout << "Destructor called for " << name << endl;
	}
};

int main()
{
	{
		Player slayer;
		slayer.set_name("Slayer");
	}

	{
		Player frank;
		frank.set_name("Frank");
		Player hero("Hero");
		hero.set_name("Hero");
		Player villain("Villanin", 100, 12);
		villain.set_name("Villanin");
	}

	Player *enemy = new Player;
	enemy->set_name("Enemy");

	Player *level_boss = new Player("Level Boss", 1000, 300);
	level_boss->set_name("Level Boss");

	delete enemy;
	delete level_boss;

	return 0;
}
