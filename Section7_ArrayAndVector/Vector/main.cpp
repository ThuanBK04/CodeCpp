/*
 * Vector is a dynamic array, an object-oriented container
 * Elements are all the same type
 * Elements initialized to zero
 * Provide bounds checking
 * If use [] - no checking to see if you are out of bounds
 * Can grow and shrink in size at execution time
 * Can use lots of cool function like sort, reverse, find and more.
*/

#include <iostream>
#include <vector>

using namespace std;

/* Delcare */
vector <char> vowels (5); // a vector contains 5 characters
vector <int> test_scores (10); // a vector contains 10 integers

/* Init */
vector <char> vowels1 {'a', 'e', 'i', 'o', 'u'};
vector <int> test_scores1 {10, 98, 89, 85, 93};
vector <double> hi_tem (365, 80.0); // 365 - size of vector; 80.0 - init the value of all elements to 80.0

int main()
{
	cout << "Default Template!" << endl; 
	return 0;
}
