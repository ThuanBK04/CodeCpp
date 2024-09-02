/*

- Often the code for constructors is very similar
- Duplicated code can lead to errors
- C++ allows delegating constructors
+ code for one constructor can call another in the initialization list
+ avoids duplicating code 

*/

#include <iostream>

using namespace std;

class Player
{
private:
	std::string name;
	int health;
	int xp;
public:
    Player();
    Player(string name_val);
    Player(string name_val, int health_val, int xp_val);
};

// Delegate no-args constructor to three-args constructors
Player::Player()
    : Player{"None", 0, 0} // Three-args constructors(line 26) called frm no-args constructor (line 25) - Concept: delegating constructor
{
	cout << "No args constructor" << endl;
}

Player::Player(string name_val)
    : Player{name_val, 0, 0}
{
	cout << "One arg constructor" << endl;
}

Player::Player(string name_val, int health_val, int xp_val) 
	: name{name_val}, health{health_val}, xp{xp_val}
{
	cout << "Three args constructor" << endl;
}

int main()
{
	Player empty;
	Player frank {"Frank"};
	Player villain {"Villain", 100, 55};

	return 0;
}
