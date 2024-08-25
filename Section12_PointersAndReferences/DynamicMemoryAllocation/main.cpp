/*

    Dynamic memory allocation:
    Allocating storage from the heap at runtime:
     * We often don't know how much storage we need until we need it
     * We can allocate storage for a variable at run time
     * Recall C++ arrays
     *  We had to explicitly provide the size and it was fixed
     *  But vectors grow and shrink dynamically
     * We can use pointers to access newly allocated heap storage
    
    Use new to allocate storage: Example:
       int *int_ptr {nullptr};
       int_ptr = new int; // allocate an integer on the heap
       cout << int_ptr << endl;
       cout << *int_ptr << endl; // garbage
       *int_ptr = 100;
       cout << *int_ptr << endl; << 100
       
       int *array_ptr {nullptr};
       int size{};
       cout << "How big do you want the array ?";
       cin >> size
       array_ptr = new int [size]; //allocate array on the heap
       delete [] array_ptr; // free allocated storage
    
     Use delete to deallocate storage
       int *int_ptr {nullptr};
       int_ptr = new int; // allocate an integer on the heap
       ...
       delete int_ptr; // frees the allocated storage

*/

#include <iostream>

using namespace std;

int main()
{
    int *int_ptr{nullptr};
    int_ptr = new int; //this integer has no name on heap, there's no way to get it except
                       // through the pointer
    cout << int_ptr << endl;

    delete int_ptr;

    size_t size{0};
    double *temp_ptr{nullptr}; // temp_ptr is on the stack

    cout << "How many temps ? ";
    cin >> size;
    temp_ptr = new double[size];
    cout << temp_ptr << endl;
    
    // Memory leak
    temp_ptr = nullptr;// From now, we lost only way to get to the storage on heap --> Memory leak
    
    delete [] temp_ptr;
    cout << endl;
    
	return 0;
}
