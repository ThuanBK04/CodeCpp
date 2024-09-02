/*

Shallow vs. Deep Copying
- Consider a class that contains a pointer as a data member
- Constructor allocates storage dynamically and initializes the pointer
- Destructor releases the memory allocated by the constructor
- What happens in the default copy constructor ?

*/

/*

(1) Shallow copy (a simple method that expects a copy): is the default behavior provided by the compiler generated copy constructor
+ memberwise copy
+ Each data memeber is copied from the source object
+ The pointer is copied not what it points to (shallow copy)
+ Problems: when we release the storage in the destructor, the other object still refers to the released
storage!

For details: problems: when we release the storage in the destructor, the other object still refers to the released
storage!
- The newly created object and the object being copied both pointing to the same area of storage in the heap
-> the problem comes into play when one of those objects is destroyed and its destructor is called
-> The object's destructor releases the memory allocated on the heap. However, the other object is still pointing
to this released area and thinks the area is still valid -> This could lead to shallow error
-> The best thing that can happen is that the program crashes while in development so that you can fix the error
-> But we'll learn how to do a deep copy and avoid the error completely

Example:
class Shallow
{
private:
	int *data; // pointer
public:
	Shallow(int d); // constructor
	Shallow(const Shallow &source); // copy
	~Shallow(); // destructor
};

Shallow::Shallow(int d)
{
	data = new int; // allocate storage
	*data = d;
}

Shallow::~Shallow()
{
	delete data; // free storage
	cout << "Destructor freeing data" << endl;
}

// Shallow copy constructor
Shallow::Shallow(const Shallow &source)
	: data(source.data)
{
	cout << "Copy constructor - shalow" << endl;
}
Shallow copy - only the pointer is copied - not what it is pointing to
Problem: source and the newly created object both point to the same data area!

// Sample main - will likely crash
int main()
{
	Shallow obj1 {100};
	display_shallow(obj1);
	// obj1's data has been released

	obj1.set_data_value(1000);
	Shallow obj2 {obj1};

	return 0;
}

Analysis: 
First, we create object1 as a shallow object
Object1 will be created and an integer will be allocated on the heap and 100 stored in it.
Now we call display shallow and a copy of object one will be created inside that function.
Since object one and the copy that was just destroyed pointed to the same memory area, object one now points to invalid storage.
If we try to access that storage from object1, our program could crash.
Also when the destructor for object1 eventually gets called, it will try to release memory that's no longer valid and will probably crash.

*/

#include <iostream>

using namespace std;

class Shallow
{
private:
	int *data; // pointer
public:
	void set_data_value(int d){*data = d;}
	int get_data_value(){return *data;}
	Shallow(int d); // constructor
	Shallow(const Shallow &source); // copy
	~Shallow(); // destructor
};

Shallow::Shallow(int d)
{
	data = new int; // allocate storage
	*data = d;
}

// It freed up this area in memory right here.
// So as far as the c++ runtime system is concerned this is no longer valid memory,
Shallow::~Shallow()
{
	delete data; // free storage
	cout << "Destructor freeing data" << endl;
}

// Shallow copy constructor
Shallow::Shallow(const Shallow &source)
	: data(source.data)
{
	cout << "Copy constructor - shalow" << endl;
}

void display_shallow(Shallow s)
{
	cout << s.get_data_value() << endl;
}

int main()
{
	Shallow obj1 {100};
	display_shallow(obj1);
	// obj1's data has been released

	obj1.set_data_value(1000);
	Shallow obj2 {obj1};

	return 0;
}
