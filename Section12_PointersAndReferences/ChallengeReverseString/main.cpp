#include <iostream>

using namespace std;

#include <string>

std::string reverse_string(const std::string &str) {
    std::string reversed;
    // Write your code below this line
    // We use const char* because we are dealing with C-style strings, 
    // where each character is represented by a char
    const char *start = str.c_str();
    const char *end = str.c_str() + str.size() -1;
    
    while (end >= start)
    {
        // The push_back() function is used to add characters to the end of a string.
        reversed.push_back(*end);
        end--;
    }
    
    // Write your code abocve this line
    return reversed;
}

int main()
{
	string str {"Hello World!"};
    string reserved = reverse_string(str);
    cout << reserved << endl;
    
	return 0;
}
