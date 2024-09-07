/*

Move constructor:
- Sometimes when we execute code the compiler creates unnamed temporary values
int total {0};
total = 100 + 200;
100 + 200 is evaluated and 300 stored in an unnamed temp value
the 300 is then stored in the variable total
- The same happens with object as well:
However, with objects there can be a great amount of overhead
if copy constructors are called over and over and over again, making copies of these temporary objects.
And when we have raw pointers and we have to do deep copies, then the overhead is even greater.
-> Use: move constructor

When is it useful ?
- Sometimes copy constructors are called many tines automatically due to the copy semantics of C++
- Copy constructors doing deep copying can have a significant performance bottleneck
- C++ introduced move semantics and the move constructor
- Move constructor moves an object rather than copy it
- Optional: if don't provide them, then the copy constructors will be called
- Recommended when you have raw pointer
- Copy elision - C++ may optimize copying away completely (RVO - Return value optimization)
In fact sometimes you may not even see the copy constructors being called,
If you experience this, it's probably due to something called copy elision.
Copy elision is a compiler optimization technique that eliminates unnecessary copying.
Compilers are really smart with their optimizations now.
And one of the common techniques is called return value optimization,
that's when the compiler generates code that doesn't create a copy every
return value from a function making the code much more efficient.

r-value references:
- Used in moving semantics and perfect forwarding
- Move semantics is all about r-value references
- Used by move constructor and move assignment operator to efficiently move an object rather than copy it
- R-value reference operator (&&) (diff with L-value references - only needs one '&')
Ex:
int x{100};
int &l_ref = x; //l-value reference
l_ref = 10; // change x to 10
int &&r_ref = 200; // r-value ref
r_ref = 300; // change r_ref to 300
int &&x_ref = x; // compiler error

l-value reference parameters:
- Ex:
int x{100}; // x is an l-value
void func(int &num); // A
func(x); // calls A - x is an l-value
func(200); // Error - 200 is an r-value
error: cannot bind non-const lvalue reference of type 'int&' to an rvalue of tyoe 'int'

r-value reference parameters:
- Ex:
int x{100}; // x is an l-value
void func(int &&num); // B
func(200); // calls B - 200 is an r-value
func(x); // Error - x is an l-value
error: cannot bind rvalue reference of type 'int&&' to an lvalue of tyoe 'int'

l-value and r-value reference parameters:
- Ex:
int x{100}; // x is an l-value
void func(int &num); // A
void func(int &&num); // B
func(x); // calls B - x is an l-value
func(200); // calls B - 200 is an r-value
No error: we can overload these functions and have both of them in our code at
the same time since they have unique signatures. And the compiler will call the correct function
depending on whether the parameter is an L-value or and R-value.

*/

/*

Example - Move class:
class Move
{
private:
	int *data; // Pointer
public:
	void set_data_value(int d){*data = d;}
	int get_data_value(){return *data;}
	Move(int d);
	Move(const Move &source);
	Move(Move &&source); // Move constructor
	~Move();
};

Move::Move(const Move &source)
{
	data = new int; // allocate storage
	*data = *source.data;

	cout << "Copy constructor - Move" << endl;
}

In main:
Vector<Move> vec;
vec.push_back(Move{10});
vec.push_back(Move{10});
-> Copy constructors will be called to copy the temps. Move 10 and move 20 are creating temporary objects, they're unnamed.
So they're going to be R-values.
-> In this program: constructors and destructors and copy constructors being called.
In fact, you can see that the copy constructor is doing several deep copies, which can be inefficient.

===>>> Add the move constructor to the class to make it much more efficient

*/

/*

===>>> Add the move constructor to the class to make it much more efficient:
What does it do ?
- Instead of making a deep copy of the move constructor
+ move the resource
+ Simple copies the address of the resource from source to the current object
(move the resource that's on the heap: just to assign the pointer from the source object to the current object)
+ And, nulls out the pointer in the source pointer
- Very efficient
More details:
You might be thinking isn't that what default member-wise copy is.
And yes, it is.
But now the difference is that we nullout the pointer in the source object.
So what we have now is an object
who owns the data on the heap and then the original object with a null pointer to that data.
This is real efficient since we're not doing a copy at all.

Syntax - rvalue reference
Type::Type(Type &&source);
Ex: Player::Player(Player &&source);
it's very similar to the syntax for a copy constructor, but it's got two differences.
First, there's no const qualifier for the parameter source.
There can't be because we need to modify it in order to null out its pointer.
And second, the parameter is an r-value reference, and you can see that with the double ampersands.

Implementation:
Move::Move(Move &&source)
	: data{source.data}
{
	source.data = nullptr;
}
Detail: we're not copying what it's pointing to, we're not doing a deep copy.
Then we null out source.data. This step is really important.
Otherwise, we end up with the equivalent of a shallow copy and not a move.
Can say that: Move constructor 'steal' the data then null out the source pointer
Example:
Vector<Move> vec;
vec.push_back(Move{10});
vec.push_back(Move{20});
Move constructors will be called for the temp r-values

*/

#include <iostream>
#include <vector>

using namespace std;

class Move {
private:
    int *data;
public:
    void set_data_value(int d) { *data = d; }
    int get_data_value() { return *data; }
    // Constructor
    Move(int d);
    // Copy Constructor
    Move(const Move &source);
    // Move Constructor
     Move(Move &&source) noexcept;
    // Destructor
    ~Move();
};

Move::Move(int d)  {
    data = new int;
    *data = d;
    cout << "Constructor for: " << d << endl;
}

// Copy ctor
Move::Move(const Move &source)
    : Move {*source.data} {
        cout << "Copy constructor  - deep copy for: " << *data << endl;
}

 //Move ctor
 Move::Move(Move &&source) noexcept 
     : data {source.data} {
         source.data = nullptr;
         cout << "Move constructor - moving resource: " << *data << endl;
 }

Move::~Move() {
    if (data != nullptr) {
        cout << "Destructor freeing data for: " << *data << endl;
    } else {
        cout << "Destructor freeing data for nullptr" << endl;
    }
    delete data;
}

int main() {
    vector<Move> vec;

    Move Move1{10};

    vec.push_back(Move1);

    vec.push_back(Move{20});
    vec.push_back(Move{30});
    vec.push_back(Move{40});
     vec.push_back(Move{50});
    vec.push_back(Move{60});
    vec.push_back(Move{70});
    vec.push_back(Move{80});


    return 0;
}
