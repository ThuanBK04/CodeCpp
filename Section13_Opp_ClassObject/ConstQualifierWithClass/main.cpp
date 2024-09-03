/*

Using const with classes:
- Pass arguments to class member methods as const
- We can also create const objects
- What happens if we call member functions on const object ?
- const - correctness

Creating a const object:
- villain is a const object so it's attributes cannot change
	const Player villain {"Villain", 100, 55};

- What happens when we call member methods on a const object ?
	const Player villain {"Villain", 100, 55};
	villain.set_name("Nice"); // Error
	cout << villain.get_name() << endl; // Error
Why get fuction produces a compiler error ?
the compiler assumes that the get name function could potentially change the object,
so it gives an error. But we need a solution to this problem.
-> We need to tell the compiler that specific methods will not modify the object.
And all we have to do is put the const modifier before the semicolon and the method prototype.

class Player
{
private:
...
public:
	string get_name() const;
	// Error if code in get_name modifies this object

};

Now the compiler will not only allow this method to be called on const objects,
it will also produce a compiler error if you try to modify any of the object attributes in the method.

*/

#include <iostream>
#include <string>

using namespace std;

class Player
{
private:
    std::string name;
    int health;
     int xp;  
public:
    std::string get_name() const  {         // consty method
        return name;
    }
    void set_name(std::string name_val)   {
        name = name_val;
    }
// Overloaded Constructors
    Player();
    Player(std::string name_val);
    Player(std::string name_val, int health_val, int xp_val);
};

Player::Player() 
    : Player {"None",0,0} {
}

Player::Player(std::string name_val) 
   : Player {name_val,0, 0}  {
}
  
Player::Player(std::string name_val, int health_val, int xp_val) 
    : name{name_val}, health{health_val}, xp{xp_val} {
}

void display_player_name(const Player &p) {
    cout << p.get_name() << endl; // as far as p dot get name is concerned, that's a const.
	                              // It can't change it, right. But there's no way to guarantee that
								  // until put the const modifier before the semicolon and the method prototype.
}

int main() {
    
    const Player villain {"Villain", 100, 55};    
    Player hero {"Hero", 100, 15};
    
   // villain.set_name("Super villain");
    cout << villain.get_name() << endl;
    cout << hero.get_name() << endl;   
    
    display_player_name(villain);
    display_player_name(hero);

    
  
    return 0;
}
