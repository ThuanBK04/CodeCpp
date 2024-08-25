#include <iostream>

using namespace std;

/*
    L-values
     * values that have names and are addressable
     * modifiable if they are not constants
    
    An l-value is an object that occupies a location in memory and addressable
*/

int x{100}; // x is an l-value
x = 1000;
string name; // name is an l-value
name = "Frank";

100 = x; // 100 is NOT an value

/*
    R-values (non-addressable and non-assignable)
     * A value that's not an l-value
     * on the right-hand side of an assignment expression
     * a literal
     * a temporary which is intended to be non-modifiable
     * r-values can be assigned to l-values explicitly
*/

int x {100}; // 100 is an r-value
int y = x + 200; // (x + 200) is an r-value because it's not addressable

/*
    L-values references
     * The references we're used are l-value references
     * * because we are referencing l-values
*/

int x{100}; // x is an l-value
int &ref1 = x; // ref1 is references to l-values
ref1 = 1000;
int &ref2 = 100; // error 100 is an r-value

// The same when we pass-by-reference
int square(int &n)
{
    retun n*n;
}
int num {10};
square(num); //ok
square(5); // Error - can't reference r-value 5

int main()
{
	cout << "Default Template!" << endl; 
	return 0;
}
