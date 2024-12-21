/*

- Using Base class references
+ We can also use Base class references with dynamic polymorphism
+ Useful when we pass objects to functions that expect a Base class reference

- Using Base class references
// Create a reference ref that's a reference to an account,
// that's the base class reference, and we initialize ref to a.
Account a;
Account &ref = a;
ref.withdraw(1000); // Account::withdraw

Trust t;
Account &ref1 = t;
ref1.withdraw(1000); // Trust::withdraw

void do_withdraw(Account &account, double amount)
{
	account.withdraw(amount);
}
Account a;
do_withdraw(a, 1000); // Account::withdraw
Trust t;
do_withdraw(t, 1000); // Trust::withdraw

*/

// This class uses dynamic polymorphism for the withdraw method
// We'll learn about virtual functions in the next video
class Account {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Account::withdraw" << std::endl;
    }
    virtual ~Account() {  }
};

class Checking: public Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Checking::withdraw" << std::endl;
    }
    virtual ~Checking() {  }
};

class Savings: public Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Savings::withdraw" << std::endl;
    }
    virtual ~Savings() {  }
};

class Trust: public Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Trust::withdraw" << std::endl;
    }
    virtual ~Trust() {  }
};

void do_withdraw(Account &account, double amount) {
    account.withdraw(amount);
}

int main() {

    Account a;
	// ref is a reference to an account. That's my base class reference
    Account &ref = a;
    ref.withdraw(1000);		    // In Account::withdraw

    Trust t;
// ref1, again, is a reference to an account, that's my base class reference.
// And I'm initializing it to t, t is a trust account. So that's perfectly valid.
// In this case, when I call ref1's withdraw,
// what's going to happen is that method call will be bound dynamically
// because it'll realize that ref1 is currently referring to a trust account.
// So it'll bind it to trusts withdrawal because they're all virtual methods.
    Account &ref1 = t;
    ref1.withdraw(1000);        // In Trust::withdraw

   Account a1;
   Savings a2;
   Checking a3;
   Trust a4;
   
   do_withdraw(a1, 1000);       // In Account::withdraw
   do_withdraw(a2, 2000);       // In Savings::withdraw
   do_withdraw(a3, 3000);       // In Checking::withdraw
   do_withdraw(a4,  4000);      // In Trust::withdraw


    return 0;
}
