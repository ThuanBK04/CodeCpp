/*

Mystring operator-
- Often declared as friend function in the class declaration

Mystring operators- (const Mystring &obj)
{
	char *buff = new char[std::strlen(obj.str) + 1];
	std::strcpy(buff, obj.str);
	for (size_t i = 0; i < std::strlen(obj.str); i++)
		buff[i] = std::tolower(buff[i]);
	Mystring temp {buff};
	delete [] buff;
	return temp;
}

*/

/*

Binary operators as global functions:
ReturnType operatorOp(const Type &lhs, const Type &rhs);
Number operator+(const Number &lhs, const Number &rhs);
Number operator-(const Number &lhs, const Number &rhs);
....

Number n1 {100}, n2 {200};
Number n3 = n1 + n2; //operator+(n1, n2)
n3 = n1 - n2; //operator-(n1, n2)

bool operator==(const Mystring &rhs, cinst Mystring &rhs)
{
	if (std::strcmp(lhs.str, rhs.str) == 0)
		return true;
	else
		return false;
}

- If declared as a friend of Mystring can access private str attribute
- Otherwise we must use getter methods

Mystring operator+
	Mystring larry {"Larry"};
	Mystring moe {"Moe"};
	Mystring stooges {" is one of the three stooges"};

	Mystring result = larry + stooges; // operator+(larry, stooges)
	result = moe + " is also a stooge"; // operator+(moe, "is also a stooge");
	result = "Moe" + stooges; // Ok with non-member function

Mystring operator+ (const Mystring &lhs, const Mystring &rhs)
{
	char *buff = new char[strlen(lhs.str) + str(rhs.str) + 1];
	strcpy(buff, lhs.str);
	strcat(buff, rhs.str);
	Mystring temp {buff};
	delete [] buff;
	return temp;
}

*/

#include <iostream>
#include "Mystring.h"

using namespace std;

int main()
{
    Mystring larry {"Larry"};
    larry.display();                                        // Larry
    
    larry = -larry;
    larry.display();                                        // larry

    cout << boolalpha << endl;
    Mystring moe{"Moe"};
    Mystring stooge = larry;

    cout << (larry == moe) << endl;             // false
    cout << (larry == stooge) << endl;          // true

  //  Mystring stooges = larry + "Moe";   
    Mystring stooges = "Larry" + moe;           // Now OK with non-member function
    stooges.display();                                      // LarryMoe
    
    Mystring two_stooges = moe + " " + "Larry";     
    two_stooges.display();                               // Moe Larry
    Mystring three_stooges = moe + " " + larry + " " +  "Curly";
    three_stooges.display();                            // Moe larry Curly

	return 0;
}
