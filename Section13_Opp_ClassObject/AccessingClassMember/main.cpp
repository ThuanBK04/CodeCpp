/*

- We can access:
+ class attributes
+ class method

- Some class members will not be accessible (more on that latter)
- We need an object to access instance variables

- If we have an object (dot operator)
+ Using the dot operator
Account frank_account;
frank_account.balance;
frank_account.deposit(1000.00);

- If we have a pointer to an object (memeber of pointer operator)
+ Deference the pointer then use the dot operator.
Account *frank_account = new Account();
(*frank_account).balance;
(*frank_account).deposit(1000.00);
+ Or use the membber of pointer operator (arrow operator)
Account *frank_account = new Account();
frank_account->balance;
frank_account->deposit(1000.00);

*/

#include <iostream>

using namespace std;

int main()
{
	cout << "Default Template!" << endl; 
	return 0;
}
