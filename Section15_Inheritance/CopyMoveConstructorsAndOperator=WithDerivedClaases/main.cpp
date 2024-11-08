/*

Copy/Move constructors and overloaded operator=
- Not inherited from the Base class
- You may not need to provide your own
+ Compiler-provided versions may be just fine
- We can explicitly invoke the base class versions from the Derived class

- Can invoke Base copy constructor explicitly
+ Derived object 'other' will be sliced
ex:
Derived::Derived(const Derived &other)
	:Base(other), {Derived initialization list}
{
	// code
}

Copy constructors
class Base{
	int value;
public:
	// same constructors as previous example
	Base (const Base &other) :value{other.value}
	{
		cout << "Base copy constructor" << endl;
	}
}
class Derived : public Base {
	int doubled_value;
public:
	// Same constructors as previous example
	Derived (const Derived &other)
	: Base (other), doubled_value {other.doubled_value}
	{
		cout << "Derived copy constructor" << endl;
	}
}

operator=
class Base
{
	int value;
public:
	// same constructors as previous example
	Base &operator=(const Base &rhs)
	{
		if (this != &rhs)
		{
			value = rhs.value;
		}
		return *this;
	}
}

*/

#include <iostream>

using namespace std;

class Base {
private:
    int value;
public:
   Base()
        : value {0}  { 
            cout << "Base no-args constructor" << endl; 
    }
    Base(int x) 
        : value {x} { 
            cout << "int Base constructor" << endl;
    }
    Base(const Base &other) 
        : value {other.value} {
         cout << "Base copy constructor" << endl;     
    }
        
    Base &operator=(const Base &rhs)  {
    cout << "Base operator=" << endl;
        if (this == &rhs)
            return *this;
        value = rhs.value;
        return *this;
    }
            
   ~Base(){ cout << "Base destructor" << endl; }
};

class Derived : public Base {
private:
    int doubled_value;
public:
    Derived() : 
        Base {}  {
            cout << "Derived no-args constructor " << endl; 
    }
    Derived(int x) 
        : Base{x} , doubled_value {x * 2} { 
            cout << "int Derived constructor" << endl; 
    }
    Derived(const Derived &other)
        : Base(other), doubled_value {other.doubled_value} {
         cout << "Derived copy constructor" << endl;     
    }
    
    Derived &operator=(const Derived &rhs) {
            cout << "Derived operator=" << endl;
        if (this == &rhs)
            return *this;
        Base::operator=(rhs);
        doubled_value = rhs.doubled_value;
        return *this;
    }
   ~Derived(){ cout << "Derived destructor " << endl; } 
};


int main() {
//    Base b {100};   // Overloaded constructor
//    Base b1 {b};    // Copy constructor
//    b = b1;          //   Copy assignment

    Derived d {100};    // Overloaded constructor
    Derived d1 {d};     // Copy constructor
    d = d1;                // Copy assignment
    
    return 0;
}
