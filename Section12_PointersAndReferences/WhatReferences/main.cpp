#include <iostream>
#include <vector>

using namespace std;

/*
What is a reference ?
 * An alias for a variable
 * Must be initialized to a variable when declared
 * Cannot be null
 * Once initialized cannot be made to refer to a different variable
 * Very useful as function parameters
 * Might be helpful to think of a reference as a constant pointer that is automatically dereferenced
 * By using references, we're not incurring the cost of copying each vector element in each loop iteration
 * 
*/

int main()
{
    /***************************************************************/
    // Using references in range-based for loop
    vector<string> stooges {"Larry", "Moe", "Curly"};

    for (auto str:stooges)
        str = "Funny"; // changes the copy

    for (auto str:stooges)
        cout << str << endl; // Larry, Moe, Curly

    // str is alias for each of elements in vector
    // or str will be a reference to the actual
    for (auto &str:stooges)
        str = "Funny"; // changes the actual

    for (auto str:stooges)
        cout << str << endl; // Funny, Funny, Funny

//    for (auto const &str:stooges)
//        str = "Funny"; // compiler error
    /***************************************************************/
    cout << "-------------------------------------------" << endl;
    int num {100};
    int &ref {num}; // ref is an alias to num
    
    cout << num << endl; // 100
    cout << ref << endl; // 100 // no using de-referencing

    cout << "---------------------" << endl;
    num = 200;
    cout << num << endl; // 100
    cout << ref << endl; // 100

    cout << "---------------------" << endl;
    ref = 300;
    cout << num << endl; // 100
    cout << ref << endl; // 100

	return 0;
}
