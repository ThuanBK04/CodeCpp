/*

Constructors and class initialization
- A derived class inherits from its base class
- The base part of the derived class must be initialized before the derived class
is initialized
- When a derived object is created
+ Base class contructor executes then derived class constructor executes

Destructors:
- Class destructors are invoked in the reverse order as constructors
- The derived part of the derived class must be destroyed before the base class destructor
is invoked
- When a derived object is destroyed
+ Derived class destructor executes then
Base class destructor executes
Each destructor shoule free resources allowcated in it's own contructors

- A derived class does not inherit
+ Base class constructors
+ Base class destructor
+ Base class overloaded assignment operators
+ Base class friend functions
- However, the derived class constructors, destructors and overloaded assignment operators
can invoke the base-class versions
- C++11 allows explicit inheritance of base 'non-special' constructors with
+ using Base::Base; anywhere in the derived class declaration
+ Lots of rules involed, often better to define constructors yourself

*/
#include <iostream>

using namespace std;

class Base {
private:
    int value;
public:
   Base() : value{0} { cout << "Base no-args constructor" << endl; }
   Base(int x) : value{x} { cout << "Base (int) overloaded constructor" << endl; }
   ~Base(){ cout << "Base destructor" << endl; }
};

class Derived : public Base {
    using Base::Base;
private:
    int doubled_value;
public:
    Derived() : doubled_value {0} { cout << "Derived no-args constructor " << endl; } 
    Derived(int x) : doubled_value {x*2}  { cout << "Derived (int) overloaded constructor" << endl; }
    ~Derived() { cout << "Derived destructor " << endl; } 
};

int main() {
//   Base b;
//    Base b{100};
 //   Derived d;
 Derived d {1000};
    
    return 0;
}