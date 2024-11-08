/*

- Passing arguments to base class constructors
+ The base part of a derived class must be initialized first
+ How can we control exactly which base class constructor is used during initialization ?
+ We can invoke the whichever Base class constructor we wish in the initialization list of the
derived class
For the example:
class Base
{
public:
	Base();
	Base(int);
	...
};
Derived::Derived(int x)
	:Base(x), {optional intializers for Derived}
{
}
-> Apply:
class Base {
	int Base;
public:
	Base(): value{0}
	{
		cout << "Base no-args constructor" << endl;
	}
	Base(int x): value{x}
	{
		cout << "int Base no-args constructor" << endl;
	}
}
class Derived:public Base
{
	int doubled_value;
public:
	Derived():Base{}, doubled_value{0}
	{
		cout << "Derived no-args constructor " << endl;
	}
	Derived(int x) : Base{x}, doubled_value{x*2}
	{
		cout << "int Derived constructor " << endl;
	}
}

-> Obsever the output of the following examples:
Base base;     // Base no-args constructor
Base base{100}; // int Base constructor
Derived derived; // Base no-args constructor
				 // Derived no-args constructor
Derived derived; // int Base constructor
				 // int Derived constructor
*/

#include <iostream>

using namespace std;

class Base {
private:
    int value;
public:
   Base() : value {0}  { 
            cout << "Base no-args constructor" << endl; 
    }
    Base(int x)  : value {x} { 
            cout << "Base (int) overloaded constructor" << endl;
    }
   ~Base() { 
       cout << "Base destructor" << endl;
    }
};

class Derived : public Base {
private:
    int doubled_value;
public:
    Derived()
        :Base {}, doubled_value {0} {
            cout << "Derived no-args constructor " << endl; 
    }
    Derived(int x) 
        :  Base{x},  doubled_value {x * 2} { 
            cout << "Derived (int) constructor" << endl; 
    }
    ~Derived() { 
        cout << "Derived destructor " << endl; 
    } 
};

int main() {
   //  Derived d;
   Derived d {1000};
    return 0;
}
