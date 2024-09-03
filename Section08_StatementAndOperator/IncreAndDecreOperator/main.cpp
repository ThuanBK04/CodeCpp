#include <iostream>

using namespace std;

int main()
{
    int counter1 = 10;
    int counter2 = 10;

    int result1  = 0;
    int result2  = 0; 

    /* Increment counter1 before using -> result1 = 11 */
    result1 = ++counter1;
    /* Increment counter2 after using -> result2 = 10 */
    result2 = counter2++;

	cout << "Result 1: " << result1 << endl;
	cout << "Result 2: " << result2 << endl;

	return 0;
}
