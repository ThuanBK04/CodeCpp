/*

- Virtual functions:
+ Refefined functions are bound statically
+ Overridden functions are bound dynamically
+ Virtual functions are overridden
+ Allow us to treat all objects generally as objects of the Base class

- Declaring virtual functions
(a) Base class
+ Declare the function you want to override as virtual in the Base class
+ Virtual functions are virtual all the way down the hierarchy from this point
+ Dynamic polymorphism only via Account class pointer or reference
Ex:
class Account {
public:
	virtual void withdraw (double amount);
	...
}
(b) Derived class
+ Override the function in the Derived classes
+ Function signature and return type must match exactly
+ Virtual keyword not required but is best practice
+ If you don't provide an overridden version it is inherited from it's base class
Ex:
class Checking : public Account
{
public:
	virtual void withdraw (double amount);
	...
}

*/

#include <iostream>

// This class uses dynamic polymorphism for the withdraw method
class Account {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Account::withdraw" << std::endl;
    }
};

class Checking: public Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Checking::withdraw" << std::endl;
    }
};

class Savings: public Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Savings::withdraw" << std::endl;
    }
};

class Trust: public Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Trust::withdraw" << std::endl;
    }
};

int main() {
    std::cout << "\n === Pointers ==== " << std::endl;
    Account *p1 = new Account();
    Account *p2 = new Savings();
    Account *p3 = new Checking();
    Account *p4 = new Trust();
    
    p1->withdraw(1000);
    p2->withdraw(1000);
    p3->withdraw(1000);
    p4->withdraw(1000);
    

    std::cout << "\n === Clean up ==== " << std::endl;
    delete p1;
    delete p2;
    delete p3;
    delete p4;
        
    return 0;
}

