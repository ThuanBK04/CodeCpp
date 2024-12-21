/*

- What is polymorphism ?
+ Fundamental to OOP
+ Polymorphism
* Compile time/early binding/static binding
* Run time/late binding/dynamic binding
+ Runtime polymorphism
* Being able to assign different meaings to the same function at run-time
+ Allow us to program more abstractly
* Think general vs.specific
* Let C++ figure out which function to call at run-time
+ Not the default in C++, run-time polymorphism is achieved via
* Inheritance
* Base class pointers or references
* virtual functions

- Types of polymorphism in C++ ?
+ Compile-time: function overloading, operator overloading
+ Run-time: function overriding

Example: an non-polymorphic example - Static binding
(1)
Account a;
a.withdraw(1000); // Account::withdraw()
(2)
Savings b;
b.withdraw(1000); // Savings::withdraw()
(3)
Account *p = new Trust();
p->withdraw(1000); // Account::withdraw()
                   // should be Trust::withdraw
Explain details: p is a pointer to an account object, so p contains the address
of an account object, now we create a trust account dynamically on the heap
and assign its address to p. Is this legal ? sure, p can hold addresses of
accounts and trust is an account. So what happens when we call the withdrawal
method for the objetc pointed to by p ? Well, we're using static binding by default
so the compiler doesn't really know what type of account object p is pointing to at runtime.
It doesn't really care. All it knows is that p is pointing to an account.
So it will call the account withdraw method. This is probably not what we expected.
It certainly isn't what we wanted since we want the trust object on the heap to 
use its own version of withdraw.
(4)
void display_account (const Account &acc)
{
	acc.display();
	// will always use Account::display
}
Account a;
display_account (a);
Savings b;
display_account (b);
And let's suppose that each account class has its own version
of a display method that displays account information based on the type of account we have.
So let's create a simple c++ function called display account, and it expects a reference to an account object.
Since all our derived classes are accounts, we can pass any of
them into this function, and this function will call the display method
for the account object passed in.
So you can see that the code creates four objects: a b c and d, one for
each type of account and then it calls display account and passes in each
of these objects to the function.
The behavior you get from the display account function may not be what you expect.
But by default c++ is doing exactly what it's supposed to do, static binding.
When the compiler sees the call to acc.display in the display
account function, it will bind the call to accounts display.
So accounts display method will be called regardless of what
object was passed in, and our display will only display whatever is in the account part of us.
There is a way for c++ to ask the account object being passed in,
hey, what kind of account are you. And then depending on that, we can have if else statements that call
the appropriate display methods. That's bad coding practice, and it also makes us program less
abstractly since then we've got to figure out what kind of object we've got and then call its functions.
There's a better way. That's where runtime polymorphism comes in.

- Consider the following example: but notice that the withdraw
methods in the class diagram are now virtual functions.
Ex: Account *p = new Trust();
P->withdraw(1000); // Trust::withdraw()
But now let's look at the pointer p.
In this case, when we call the withdraw method of the object
pointed to by p, the trust withdraw method will be called.
That's what we want and that's pretty cool.
The idea of using virtual functions tells the compiler not to bind the
calling compile time but instead defer the binding to runtime.
And at runtime, a check will occur to see exactly what p
is pointing to and then that object's method will be called.
In this case, the trust withdraw method.

Ex: void display_account (const Account &acc)
{
	acc.display();
	// will always use Account::display
}
Account a;
display_account (a);
Savings b;
display_account (b);
Explain: Now we have virtual display functions in our account class.
So whenever we use a pointer or a reference to a base
class, the binding is done at runtime, not at compile time.
So now we create four objects: a b c and d, each as a different type of account.
Now when we pass these objects to the display account function,
the binding of acc.display will take place at runtime and call
the display method based on the type of object being passed in.

*/

#include <iostream>
#include <memory>

class Base {
public:
    void say_hello() const {
        std::cout << "Hello - I'm a Base class object" << std::endl;
    }
};

class Derived: public Base {
public:
    void say_hello()  const {   
        std::cout << "Hello - I'm a Derived class object" << std::endl;
    }
};

void greetings(const Base &obj) {
    std::cout << "Greetings: " ;
    obj.say_hello();
}

int main() {
    Base b;
    b.say_hello();
    
    Derived d;
    d.say_hello();
    
    greetings(b);
    greetings(d);
    
    Base *ptr = new Derived();
    ptr->say_hello();
    
    std::unique_ptr<Base> ptr1 = std::make_unique<Derived>();
    ptr1->say_hello();
    
    
    
   delete ptr;
    
    return 0;
}

