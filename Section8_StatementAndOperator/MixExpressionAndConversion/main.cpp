#include <iostream>

using namespace std;

/* 
 * Note1: the lower's promoted to a higher: 2 * 5.2 -> 2 is promoted to 2.0 
*/

/* Note2: the higher's demoted to a lower
int num {0};
num = 100.2;
*/

/* Note3: Explicit type casting - static_cast<type>
 * static_cast<type> : modern c++: double check to make sure that it can be coverted to a double
 * aver = (double)total/count; -> old c style cast: coverted whatever is requested

int total_amount {100};
int total_number {8};
double average {0.0};

average = total_amount / total_number; result: 12
average = static_cast<double>(total_amount) / total_number; result: 12.5
*/

int main()
{
	cout << "Default Template!" << endl; 
	return 0;
}
