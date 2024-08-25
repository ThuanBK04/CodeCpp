/*

    Subtracting two pointers
     * Determine the number of elements between the pointers
     * Both pointers must point to the same data type
        int n = int_ptr2 - int_ptr1;

    Comparing two pointers
     * Determine if two pointers point to the same location
     * Does not compare the data where they point
        string s1 {"Frank"};
        string s2 {"Frank"};
        
        string *p1 {&s1};
        string *p2 {&s2};
        string *p3 {&s1};
        
        cout << (p1 == p2) << endl; //false
        cout << (p1 == p3) << endl; //true
*/

#include <iostream>

using namespace std;

int main()
{
    int scores[] {100, 95, 89, 68, -1};
    int *score_ptr{scores};

/*
Result:
100
95
89
68
*/
    while(*score_ptr != -1)
    {
        cout << *score_ptr << endl;
        score_ptr++;
    }

/*
Result:
100
95
89
68
*/
    cout << "\n--------------------------" << endl;
    score_ptr = scores;
    while(*score_ptr != -1)
        cout << *score_ptr++ << endl; // dereference the pointer and then increment pointer after use
    
	return 0;
}
