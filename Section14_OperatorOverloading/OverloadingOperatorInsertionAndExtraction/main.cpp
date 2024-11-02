/*

stream insertion and extraction operators (<<, >>):
- Doesn't make sense to implement as member methods
+ Left operand must be a user-defined class
+ Not the way we normally use these operators

Mystring larry;
larry << cout; // huh ?

Player hero;
hero >> cin; // huh ?

-> We're going to overload these operators as non-memeber functions

*/

/*

stream insertion operator (<<)

std::ostream &operator<<(std::ostream &os, const Mystring &obj)
{
	os << obj.str; // if friend function
	// os << obj.get_str(); // if not friend function
	return os;
}

- Return a reference to the ostream so we can keep inserting
- Don't return ostream by value

*/

/*

stream extraction operator (>>)
std::istream &operator>>(std::istream &is, Mystring &obj)
{
	char *buff = new char[1000];
	is >> buff;
	obj = Mystring{buff}; // if you have copy or move assignment
	delete [] buff;
	return is;
}

- Return a reference to the istream so we can keep inserting
- Update the object passed in

*/

#include <iostream>
#include "Mystring.h"

using namespace std;

int main() {
    
    Mystring larry {"Larry"};
    Mystring moe {"Moe"};
    Mystring curly;

    cout << "Enter the third stooge's first name: ";
    cin >> curly;

    cout << "The three stooges are " << larry << ", " << moe << ", and " << curly << endl;

    cout << "\nEnter the three stooges names separated by a space: ";
    cin >> larry >> moe >> curly;

    cout << "The three stooges are " << larry << ", " << moe << ", and " << curly << endl;

    return 0;
}
