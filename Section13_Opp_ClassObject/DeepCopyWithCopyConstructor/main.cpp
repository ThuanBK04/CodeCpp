/*

User-provided copy constructor
- Create a copy of the pointed-to data
- Each copy will have a pointer to unique storage in the heap and both areas will contain the same data
- Deep copy when you have a raw pointer as a class data member

*/

#include <iostream>

using namespace std;

class Deep
{
private:
	int *data; // Pointer
public:
	void set_data_value(int d){*data = d;}
	int get_data_value(){return *data;}
	Deep(int d);
	Deep(const Deep &source);
	~Deep();
};

Deep::Deep(int d)
{
	data = new int; // allocate storage
	*data = d;
}

Deep::~Deep()
{
	delete data; // free storage
	cout << "Destructor freeing data" << endl;
}

// Deep copy constructor
/*

Solution 1:
Deep::Deep(const Deep &source)
{
	data = new int; // allocate storage
	*data = *source.data;

	cout << "Copy constructor - Deep" << endl;
}

*/

// Deep copy constructor - delegating constructor
/* Solution 2: Delegate to Deep(int) and pass in the int (*source.data) source is pointing to */
Deep::Deep(const Deep &source)
	:Deep{*source.data}
{
	cout << "Copy constructor - Deep" << endl;
}

// When s goes out of scope the destructor is called and releases data
// No problem: since the storage being releases is unique to s
void display_deep(Deep s)
{
	cout << s.get_data_value() << endl;
}

// Not crash
int main()
{
	Deep obj1 {100};
	display_deep(obj1);

	obj1.set_data_value(1000);
	Deep obj2 {obj1};

	return 0;
}
