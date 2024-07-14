#include <iostream>
#include <cstring>

/* C-style
 * * Sequence of characters
 * contiguous in memory
 * implemented as an array of characters
 * terminated by a null character (null)
 * null - character with a value of zero
 * Refered to as zero or null terminated strings
 * * String literal
 * sequence of characters in double quotes, e.g "Frank"
 * const
 * terminated with null character
 */

using namespace std;

int main()
{
    /* Ex1: declaring variables */
    char my_name[] {"Frank"};
    my_name[5] = 'y'; /* Problem: the string will not be terminated by null character */
	cout << "string 0: " << my_name << endl;

    /* Ex2: declaring variables */
    char my_name1[8] {"Frank"};
    my_name1[5] = 'y'; /* ok because string allocated in memory will be F-r-a-n-k-y-\0-\0 */
	cout << "string 1: " << my_name1 << endl;
	return 0;

    /* Ex3: declaring variables */
    char my_name2[8];
    /* my_name2 = "Frank"; */ /* error because my_name2 is an array, a string needs to be terminated by
                                 null but we could not know what data's contained in array */
	/* Solution: Use function called string copy */
    strcpy (my_name2, "Frank");
    cout << "string 2: " << my_name2 << endl;

	return 0;
}
