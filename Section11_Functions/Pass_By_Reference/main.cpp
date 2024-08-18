/*
 * Pass by Reference
 * 
 * Sometimes we want to be able to change the actual parameter from within the function body
 * In order to achieve this we need the location or address of the actual parameter
 * We saw how this is the effect with array, but what about other variable types ?
 * We can use reference parameters to tell the compiler to pass in a reference to the actual parameter
 * The formal parameter will now be an alias for the actual parameter
 * 
 * Useful:
 *  Change an actual parameter if we need to
 *  Don't make copy of the parameter, which could be large and take time
 *
 */

#include <iostream>
#include <vector>

using namespace std;

/* Example 1: SWAP */
// a and b are reference parameters
// so when calling this function with x and y, a and b become aliases to x and y, respectively
void swap (int &a, int &b);

void swap (int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

/* Example 2: vector example - pass by value */
// -> Issue: we're using pass by value, so we're making a complete copy of the vector object in 
// the function, so the formal parameter v will be a copy of the actual parameter data in this case
// To make a copy, we need to allocate storage and copy values over, if the vector is very large,
// we could run it to performance and storage issues -> Use pass by reference instead to avoid the copy
void printPassValue(vector<int> v);

void printPassValue(vector<int> v)
{
    for (auto num: v)
        cout << num << endl;
}

/* vector example - pass by reference */
/* declare the formal parameter v as a reference parameter using ampersand */
/* v is an alias to the data variable - line 70*/
/* here, we pass in the location of the data behind the scenes */
void printPassReference(const vector<int> &v);

void printPassReference(const vector<int> &v)
{
    for (auto num: v)
        cout << num << endl;
}

int main()
{
	int x{10}, y{20};
    cout << x << " " << y << endl;
    swap(x, y);
    cout << x << " " << y << endl;

    cout << "##########################" << endl;

    vector<int> data {1, 2, 3, 4, 5};
    printPassValue(data);
    cout << "##########################" << endl;
    printPassReference(data);

	return 0;
}
