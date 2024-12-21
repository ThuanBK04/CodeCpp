/*

	The override specifier
- We can override Base class virtual functions
- The function signature and return must be exactly the same
- If they are different then we have redefinition not overriding
- Redefinition is statically bound
- Overriding is dynamically bound
- C++11 provides an override specifier to have the compiler ensure overriding
Ex:
class Base
{
public:
	virtual void say_hello() const
	{
		std::cout << "Hello - I'm a Base class object" << std::endl;
	}
	virtual ~Base() {}
};
class Derived: public Base
{
public:
	virtual void say_hello() // Notice I forgot the const - Not overrinding
	{
		std::cout << "Hello - I'm a derived class object" << std::endl;
	}
	virtual ~Derived() {};
}
Base *p1 = new Base();
p1->say_hello(); // "Hello - I'm a Base class object"
Base *p2 = new Derived();
p1->say_hello(); // "Hello - I'm a Base class object"
-> Use override specifier
public:
	virtual void say_hello() const
	{
		std::cout << "Hello - I'm a Base class object" << std::endl;
	}
	virtual ~Base() {}
};
class Derived: public Base
{
public:
	virtual void say_hello() override // Produces compiler error
									  // Error: marked override but does not override
	{
		std::cout << "Hello - I'm a derived class object" << std::endl;
	}
	virtual ~Derived() {};
}

*/

#include <iostream>

class Base {
public:
    virtual void say_hello() const {
        std::cout << "Hello - I'm a Base class object" << std::endl;
    }
    virtual ~Base() {}
};

class Derived: public Base {
public:
    // if not have const, he compiler is concerned,
    // this function, right here in my derived class,
    // is redefining the base class function, not overriding it.
	// So it's going to statically bind it rather than dynamically bind it.
    virtual void say_hello()  const override {             // Notice I forgot the const 
        std::cout << "Hello - I'm a Derived class object" << std::endl;
    }
    virtual ~Derived() {}
};


int main() {

// here's p1 and p1 is a pointer to a base object.
// And I'm instantiating a base object and pointing right to it.
// So now when I call say hello via that p1 pointer,
// obviously, this is going to do dynamic binding,
// and it's going to bind it to my base class since that's what I'm pointing to so
// this will call base say hello.
    Base *p1 = new Base();      // Base::say_hello()
    p1->say_hello();

// Here I have p2 is a pointer to a derived object,
// and I'm instantiating a derived object.
// So in this case, what's going to happen is this is not a base class pointer,
// this is just a regular old pointer to an object.
// So in this case, it's going to be statically bound, and we're going to call derived say hello.
    Derived *p2 = new Derived();    // Derived::say_hello()
    p2->say_hello();

// P3 is pointing to a base object, and it's currently
// pointing to the derived, right.
// If not have const
// The problem here is since we did not override instead we redefined,
// this will not be bound dynamically, it'll be bound statically.
// So as far as the compiler is concerned,
// I've got a base pointer right here, so it's going to bind it to base say hello.
// But I really wanted it to bind to derive say hello.
    Base *p3 = new Derived();   //  Base::say_hello()   ?????   I wanted Derived::say_hello()
    p3->say_hello();

    return 0;
}
