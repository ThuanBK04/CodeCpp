#include <iostream>

using namespace std;

/*
    Pointers to constants
     * The data pointed to by the pointers is constant and cannot be changed
     * The pointer itself can change and point somewhere else
*/

int high_score {100};
int low_score {65};

const int *score_ptr {&high_score};

*score_ptr = 86; // Error
score_ptr = &low_score;

/*
     Constant pointers
     * The data pointed to by the pointers can be changed
     * The pointer itself cannot change and point somewhere else
*/

int high_score1 {100};
int low_score1 {65};

const int *score_ptr1 {&high_score1};

*score_ptr1 = 86; // OK
score_ptr1 = &low_score; // ERROR

/*
     Constant pointers to constants
     * The data pointed to by the pointers is constant and cannot be changed
     * The pointer itself cannot change and point somewhere else
*/

int high_score2 {100};
int low_score2 {65};

const int *const score_ptr2 {&high_score2};

*score_ptr2 = 86; // OK
score_ptr2 = &low_score; // ERROR

int main()
{
	cout << "Default Template!" << endl; 
	return 0;
}
