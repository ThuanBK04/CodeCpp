/*

class Class_Name
{
	// delaration (s); // define the structure and behavior of our class
}

Example:
class Player
{
	// atributes
	std::string name; // no garbage data when initilizing because our C++ string class, standard string class has a default initializes
	int health {100}; // initilizing
	int xp;

	// methods
	void talk(std::string text_to_say);
	bool is_dead();
}
Player frank;
Player hero;
Player *enemy {nullptr};
enemy = new Player();
delete enemy;

Account frank_account;
Account jim_account;
Account accounts[] {frank_account, jim_account};
std::vector<Account> accounts1 {frank_account};
accounts1.push_back(jim_account);

*/

#include <iostream>

using namespace std;

int main()
{
	cout << "Default Template!" << endl; 
	return 0;
}
