/*

The protected class member modifier
class Base
{
	protected:
	// protected Base class members ...
}
+ Accessible from the Base class itself
+ Accessible from classes Derived from Base
+ Not accessible by objects of Base or Derived

- Concept (1): Access with public inheritance
Base Class: public a; protected b; private c
     via public inheritance
Access in Derived class: public a; protected b; no access c (but it is still available for objects of Derived class
because it is one of your parent)

- Concept (2): Access with protected inheritance
Base Class: public a; protected b; private c
     via protected inheritance
Access in Derived class: protected a; protected b; no access c

- Concept (3): Access with private inheritance
Base Class: public a; protected b; private c
     via protected inheritance
Access in Derived class: private a; private b; no access c

*/

#include <iostream>

using namespace std;

class Base {
    // Note friends of Base have access to all 
public:
    int a {0};
    void display() { std::cout << a << ", " << b << ", " << c << endl; } // member method has access to all
protected:
    int b {0};
private:
    int c {0};
};

class Derived: public Base {
    // Note friends of Derived have access to only what Derived has access to

    // a will be public
    // b will be protected
    // c will not be accessible
public:
    void access_base_members() {
        a = 100;    // OK
        b = 200;    // OK
     //   c = 300;    // not accessible
    }
    
};

int main() {
    
    cout << "=== Base member access from base objects ===========" << endl;
    Base base;
    base.a = 100;   // OK
//    base.b = 200;   // Compiler Error
//    base.c = 300;   // Compiler Error
    
    cout << "=== Base member access from derived objects ===========" << endl;
    Derived d;
    d.a = 100;  // OK
//    d.b = 200;  // Compiler Error
//    d.c = 300;  // Compiler Error
    return 0;
}
