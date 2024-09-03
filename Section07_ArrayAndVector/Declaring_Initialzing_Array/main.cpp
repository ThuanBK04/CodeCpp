#include <iostream>

using namespace std;

int arr1[10] {3, 5}; // init to 3, 5 and remaining to 0

const int leng_arr2 {10};
double arr2[leng_arr2] {0}; // init all to zero

int arr3 [] {1, 2, 3, 4, 5}; //size automatically calculated

int main()
{
	cout << "Default Template!" << endl; 
	return 0;
}
