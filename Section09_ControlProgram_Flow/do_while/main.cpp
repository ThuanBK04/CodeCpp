#include <iostream>

using namespace std;

/*******************************************************
 * Write your code in the provided area.
 * 
 * This function should use a do while loop to iterate over
 * the automatically provided vector (vec) of characters looking 
 * for the first occurrence of a lowercase English vowel ('a','e','i','o','u').
 * 
 * If a vowel is found, you should display to cout:
 * 
 * "Vowel found: " followed by the vowel that was found.
 * 
 * If no vowel is found in the vector, then you should display to cout:
 * 
 * "No vowel was found"  
 * 
 * For example, below are several examples of vectors and what your output should be:
 * 
 * {'f','r','a','n','k'}    Vowel found: a
 * {'F','R','A','N','K'}    No vowel was found
 * {'h','e','l','l','o'}    Vowel found: e
 * {}                       No vowel was found
 * {'x','y','z','o'}        Vowel found: o
 * 
 * Please do NOT add std::endl or '\n' to your output statement.
 * *****************************************************/
 
/*******************************************************
void find_first_vowel(const std::vector<char>& vec) {
    //---- WRITE YOUR CODE BELOW THIS LINE----
    unsigned i = 0;
    int vowelFound = 0;
    do {
        if (vec.size() > 0)
        {
            if ((vec.at(i) == 'a') || (vec.at(i) == 'e') || (vec.at(i) == 'i') || (vec.at(i) == 'o') || (vec.at(i) == 'u'))
            {
                vowelFound = 1;
                cout << "Vowel found: " << vec.at(i);
            }
        }

        i++;
    } while ((i < vec.size()) && (vowelFound == 0) && (vec.size() > 0));

    if (0 == vowelFound)
    {
        cout << "No vowel was found";
    }
    //---- WRITE YOUR CODE ABOVE THIS LINE----
}
 ******************************************************/

int main()
{
	cout << "Default Template!" << endl; 
	return 0;
}
