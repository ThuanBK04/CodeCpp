/*

- Using and redefining Base class methods
+ Derived class can directly invoke Base class method
+ Derived class can override or redefine Base class methods
+ Very powerful in the context of polymorphism
Ex:
class Account
{
public:
	void deposit (double amount) {balance += amount;}
};
class Savings_Account: public Account {
public:
	void deposit(double amount) // Redefine Base class method
	{
		amount += some_interest;
		Account::deposit(amount); // invoke call Base class method
	}
}

- Static binding of method calls:
+ Binding of which method to use is done at compile time
+ Default class object will use Derived::deposit
+ But, we can explicitly invoke Base::deposit from Derived::deposit
+ OK, but limited - much more powerful approach is dynamic binding which we will see in the
next section
Example: 
Base b; 
b.deposit(1000.0); // Base::deposit

Derived d;
d.deposit(1000.0); // Derived::deposit

Base *ptr = new Derived();
ptr->deposit(1000.0); // Base::deposit ???
Explain this case: We have a pointer ptr to a base object but we created a derived object 
on the heap and assign it to the pointer. This is valid since the derived is a base.
Now, if we call the deposit method through compiler.Compiler will call the base classes 
deposit method because it sees that pointer is a pointer to a base class

*/

#include <iostream>
#include "Savings_Account.h"

using namespace std;


int main() {
    cout << "\n===== Account class ===================" << endl;
    Account a1 {1000.0};
    cout << a1 << endl;         // Account balance: 1000
    
    a1.deposit(500.0);
    cout << a1 << endl;         // Account balance: 1500
    
    a1.withdraw(1000);            // Account balance: 500
    cout << a1 << endl;
    
    a1.withdraw(5000.0);         // Insufficient funds
    cout << a1 << endl;         // Account balance: 500

 cout << "\n===== Savings Account class ===========" << endl;
    Savings_Account s1 {1000, 5.0}; 
    cout << s1 << endl;         // Savings Account balance: 1000, Interest rate: 5
    
    s1.deposit(1000);
    cout << s1 << endl;          // Savings Account balance: 2050, Interest rate: 5
    
    s1.withdraw(2000);
    cout << s1 << endl;          // Savings Account balance: 50, Interest rate: 5
    
    s1.withdraw(1000);            // Insufficient funds
    cout << s1 << endl;         // Savings Account balance: 50, Interest rate: 5
    
    
    return 0;
}
