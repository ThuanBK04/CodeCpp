/*

Class Member Access Modifiers

public: accessible everywhere

private: accessible only by memebers or friends of the class

protected: used with inheritance

*/

/*

public

class Class_Name
{
	public: anything after this will be public until see a different access modifier
	// declaration (s)
};

private

class Class_Name
{
	private:
	// declaration (s)
};

protected: it and private are pretty much the same, the different comes in when using inheritance

class Class_Name
{
	protected:
	// declaration (s)
};

Example:
class Player
{
private:
	std::string name;
	int health;
	int xp;
public:
	void talk(std::string text_to_say);
	bool is_dead();
};

Player frank;
frank.name = "Frank"; // compiler error because it's private and not accessible from outside the class
frank.talk ("Ready"); //Ok

Player *enemy = new Player();
enemy->xp = 100; // compiler error
enemy->talk("Hello"); // compiler error

*/

#include <iostream>

using namespace std;

int main()
{
	cout << "Default Template!" << endl; 
	return 0;
}
