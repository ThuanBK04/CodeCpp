#include <iostream>
#include <vector>

using namespace std;

/**
Given a vector of integers, determine how many integers are present before you see the value -99 .
Note, it's possible -99  is not in the vector! If -99  is not in the vector then the result will be equal
to the number of elements in the vector.
 */
int count_numbers(const vector<int> &vec) {
    //---- WRITE YOUR CODE BELOW THIS LINE----
    int count = 0;
    while ((count < vec.size()) && (vec[count] != (-99)))
    {
        count++;
    }

    //---- WRITE YOUR CODE ABOVE THIS LINE----
    //---- DO NOT MODIFY THE CODE BELOW THIS LINE-----
    return count;
}

int main()
{
	cout << "Default Template!" << endl; 
	return 0;
}
