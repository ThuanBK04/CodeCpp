/*
Syntax:
Unary operators as member methods (++, --, -, !)
Returntype Type::operatorOp();

Binary operators as member methods (+, -, ==, !=,... )
ReturnType Type::operatorOp (const Type &rhs);

*/

/*

Unary operators as member methods (++, --, -, !)
Returntype Type::operatorOp();
Number Number::operator-() const;
Number Number::operator++() const; // pre-increment
Number Number::operator++() const; // post-increment
bool Number::operator!() const;

Number n1 {100}; 
Number n2 = -n1;; // n1.operator-()
n2 = ++n1; // n1.operator++()
n2 = n1++; // n1.operator++(int)

*/

/*

Mystring operator- make lowercase
Mystring larry1 {"LARRY"};
Mystring larry2;
larry1.display(); // LARRY
larry2 = -larry1; //larry1.operator-()
larry1.display(); // LARRY
larry2.display(); // larry

Mystring Mystring::operator-() const
{
	char *buf = new char[std::strlen(str) + 1];
	std::strcpy(buff, str);
	for (size_t i = 0; i < std::strlen(buff); i++)
		buff[i] = std::tolower(buff[i]);
	Mystring temp {buff};
	delete [] buff;
	return temp;
}

*/

/*

Binary operators as member methods (+, -, ==, !=,... )
ReturnType Type::operatorOp (const Type &rhs);
Number Number::operator+(const Number &rhs) const;
Number Number::operator-(const Number &rhs) const;
Number Number::operator==(const Number &rhs) const;
Number Number::operator<(const Number &rhs) const;

Number n1 {100}, n2 {200};
Number n3 = n1 + n2; //n1.operator+(n2)
n3 = n1 - n2; //n1.operator-(n2)

Mystring operator==
bool Mystring::operator==(const Mystring &rhs) const
{
	if (std::strcmp(str, rhs.str) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// if (s1 == s2) // s1 and s2 are Mystring objects

*/

/*

Mystring operator+ (concatenation)
Mystring larray{"Larry"};
Mystring moe{"Moe"};
Mystring stooges {" is one of the three stooges"};
Mystring result = larry + stooges; // larry.operator+(stooges)
result = moe + " is also a stooge"; // moe.operator+(" is also a stooge")
result = "Moe" + stooges; // "Moe".operator+(stooges) ERROR

----> Note:
- Notice that we can also use c style strings on the right-hand side.
This is because we have a mystring constructor that can
construct mystring objects from a c-style string.
-------> Limitation:  The only limitation to overloading operators as member functions
is that the object on the left-hand side must be an object of the class you're using.

Mystring Mystring::operator+(const Mystring &rhs) const
{
	size_t buff_size = std::strlen(str) + std::strlen(rhs.str) + 1;
	char *buff = new char[buff_size];
	std::strcpy(buff, str);
	std::strcat(buff, rhs.str);
	Mystring temp{buff};
	delete [] buff;
	return temp;
}

*/

#include <iostream>
#include "Mystring.h"

using namespace std;

int main()
{
    Mystring larry{"LARRY"};
    Mystring moe{"Moe"};

    Mystring stooge = larry;
    larry.display();
    moe.display();

    cout << (larry == moe) << endl;
    cout << (larry == stooge) << endl;

    larry.display();
    Mystring larry2 = -larry;
    larry2.display();

	return 0;
}
