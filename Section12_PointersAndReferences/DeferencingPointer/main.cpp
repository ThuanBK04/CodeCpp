#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<string> stooges{"Larry", "Moe", "Curly"};
    vector<string> *vector_ptr{nullptr};
    
    vector_ptr = &stooges;
    
    // *vector_ptr <-> stooges
    cout << "First stooges: " << (*vector_ptr).at(0) << endl;

    cout << "Stooges: ";

    for (auto stooge: *vector_ptr)
        cout << stooge << " ";
    cout << endl;

	return 0;
}
