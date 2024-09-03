/*

Static class member:
- Class data members can be declated as static
+ A single data member that belongs to the class, not the objects
+ Useful to store class-wide information
+ When we declare class data members as static, we're telling the c++ compiler that these data members
belong to the class, not to any specific object.

- Class functions can be declared as static
+ Independent of any objects
+ Can be called using the class name
+ A static function only has access to static data members.
As example bellow: get_num_players only has access to data member num_plyers

- An application of using static:
To return num players. For example, suppose we wanted to know how many player objects
we have active in our application at any point in time.
We could create a global variable and then increment it and decrement it in the code
whenever we create an object or delete an object.
This is really hard to do though since we really can't be sure when
constructors are called and when the structures are being called.
So a better solution is to create a static variable that's part of the player class,
and then we can manipulate that variable directly within the player class.
And then whenever we need to know how many player objects there are,
we can simply ask the player class.

Example:
Player class-static members:

class Player {
private:
	static int num_plyers;
public:
	static int get_num_players();
...
};

Typically in Player.cpp
#include "Player.h"
int Player::num_players = 0;

int Player::get_num_players()
{
	return num_players;
}

// An application of using static:
To return num players. For example, suppose we wanted to know how many player objects
we have active in our application at any point in time.
We could create a global variable and then increment it and decrement it in the code
whenever we create an object or delete an object.
This is really hard to do though since we really can't be sure when
constructors are called and when the structures are being called.
So a better solution is to create a static variable that's part of the player class,
and then we can manipulate that variable directly within the player class.
And then whenever we need to know how many player objects there are,
we can simply ask the player class.
// Note: A static function only has access to static data members.
Player::Player(string name_val, int health_val, int xp_val)
	: name{name_val}, health{health_val}, xp{xp_val}
{
	++num_players;
}

Player::~Player()
{
	--num_players;
}

*/

#include <iostream>
#include "Player.h"

using namespace std;

void display_active_players() {
    cout << "Active players: " << Player::get_num_players() << endl;
}

int main() {
    display_active_players();
    Player hero{"Hero"};
    display_active_players();
    
    {
        Player frank{"Frank"};
        display_active_players();
    }
    display_active_players();
    
    Player *enemy = new Player("Enemy", 100, 100);
    display_active_players();
    delete enemy;
    display_active_players();    



    return 0;
}

