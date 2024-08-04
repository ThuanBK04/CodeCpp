/* * C++ string
 * std:: string is a class in the standard template library (stl)
 * To use it needs #include <string>
 * String in the standard namespace -> To use them without using namespace standard, must prefix
 *        with standard and scope resolution operator, this's also true for the standard string method
 * Stored contiguously in memory
 * Unlike c-style strings fixed in size, c++ strings are dynamic and can grow. shrink 
 *                                       as needed at runtime
 * C++ string work with the stream insertion and extraction operators (input, output streams)
 * Lots of useful memeber functions
 * Our familiar operators can be used (+, =, <, <=,...) -> huge advantage over c-style strings,
 *                               because c-style strings don't work well with those operators
 * Even though c++ strings are prefered in most cases sometimes still need to use c-style strings
 *     Maybe, interface with a library optimized for c-style strings
 *     -> C++ string can be easily coverted to C-style strings if neeeded
 * Safer
 *   Like vectors, C++ strings provides methods that can bounce check and allow to find errors in code
 *   so can fix them before program goes into production
*/

#include <iostream>
#include <string>

using namespace std;

/* Declaring and initializing
 * Unlike c-style strings, c++ strings always initialized
 */
/*
string s1; // Initialized to an empty string, no garbage
string s2 {"Frank"}; // Frank
string s3 {s2}; // Frank - S3 initialized from S2, a copy of S2 created, both of them are Frank
                // but different areas of memory
string s4 {"Frank", 3}; // Fra
string s5 {s3, 0, 2}; Fr
string s6 (3, 'X'); // XXX - This uses constructor syntax with the paretheses, not curlies
*/

/* Assignment
string s1;
s1 = "C++ Rocks!";
string s2 {"Hello"};
s2 = s1;
*/

/* Concatenation
string part1 {"C++"};
string part2 {"is a powerful"};

string sentence;

sentence = part1 + " " + part2 + " language"; C++ is a powerful language
*/

/* Accessing characters [] and at() method
Ex1:
string s1;
string s2 {"Frank"};
cout << s2[0] << endl; // F
cout << s2.at(0) << endl; //F
s2[0] = 'f'; //frank
s2.at(0) = 'p'; //prank

Ex2:
string s1 {"Frank"};
for (char c: s1)
    cout << c << endl; F r a n k

Ex3:
string s1 {"Frank"};
for (int c: s1)
    cout << c << endl; 70(F) 114(r) 97(a) 110(n) 107(k) 0(null character)
*/

/*
Comparing
The objects are compared character by character lexically

Can compare:
    two std:string objects
    std::string object and C-style string literal
    std::string object and C-style string variable
*/

/*
Substrings - substr()
Extracts a substring from a std::string
    object.substr(start_index, length)
string s1 {"This is a test"};
cout << s1.substr(0,4); // This
cout << s1.substr(5,2); // is
cout << s1.substr(10,4); // test
*/

/*
Searching - find()
Returns the index of a substring in a std::string
    object.find(search_string)
cout << s1.find("is"); // 2
cout << s1.find("is", 4); // 5 - search a string start at index 4
cout << s1.find("XX"); // string:: npos
*/

/*Removing characters - erase() and clear()
Removing a substring of characters from a std::string
    object.erase(start_index, length)
string s1 {"This is a test"};
cout << s1.erase(0,5);// is a test
cout << s1.erase(5,4);// is a
cout << s1.clear();// empties string s1
*/

/*Length
string s1 {"Frank"};
cout << s1.length() << endl; //5
*/

/*
Input >> and getline()
Reading std::string from cin

string s1;
cin >> s1; // Hello there
           // Only accepts up to the first space
cout << s1 << endl; //Hello

getline(cin,s1); //Read entire line until \n
cout << s1 << end; // Hello there

getline(cin,s1,'x'); //this isx (3rd is the character that you want getline to stop reading input at)
cout << s1 << end; //this is
*/

/*
s1 = "The secret word is Boo";
string word{};

cout << "Enter the word to find: ";
cin >> word;

size_t position = s1.find(word);
if (position != string::npos)
{
    cout << "Found" << word << " at position: " << position << endl;
}
else
{
    cout << "Sorry, " << word << " not found" << endl;
}
*/


int main()
{
	cout << "Default Template!" << endl; 
	return 0;
}
