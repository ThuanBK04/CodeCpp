/*

- Default constructor parameters
+ Can often simplify our code and reduce the number of overloaded constructors
+ Same rules apply as we learned with non-memeber functions
- Default constructor parameters will match the signature, we don't have to do anything to it.
These default parameters will automatically be supplied by the compiler when need them

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
	// Constructor with default parameter values
	Player(string name_val = "None",
		   int health_val = 0,
		   int xp_val = 0);
//    Player();
//    Player(string name, int health);
};

Player::Player(string name_val, int health_val, int xp_val)
	: name{name_val}, health{health_val}, xp{xp_val}
{
	cout << "Three-args constructor" << endl;
}

/*
Player::Player()
{
    
}
*/

/*
Player::Player(string name, int health)
{
    
}
*/

int main()
{
    Player empty; // An error will be triggered if we delare no-args constructor
                  // empty object will be initialize with the default parameters
    Player frank{"Frank"}; // An error will be triggered if we delare two-args constructor
    Player hero{"Hero", 100};
    Player villain("Villain", 100, 50);
	return 0;
}
