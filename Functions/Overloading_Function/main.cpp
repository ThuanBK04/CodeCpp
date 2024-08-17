/*
 * Overloading functions
 * 
 * We can have functions that have different parameter lists that have the same name
 * 
 * Abstraction mechanism since we can just think 'print' for example
 * 
 * A type of polymorphism
 *  We can have the same name work with different data types to execute similar behavior
 * The compiler must be able to tell the functions apart based on the parameter lists and argument
 *  suppiled
 * 
 * Example:
 *  void display (int n);
 *  void display (double d);
 *  void display (std::string s);
 *  void display (std::string s, std::string t);
 * -> When call display and pass in your data, the compiler will check the type of the argument in
 *  the function and match it to one of the available overloaded display functions
 * -> If can't match or can't convert the argument  to one that matches -> get a compiler error
 *
 * One restriction to function overloading:
 *  the return type is not considered when the compiler's trying to determine, which function to call
 * Ex: compiler error: no params for functions bellow:
 *  int get_value();
 *  double get_value();
 * cout << get_value() << endl; -> which one ? -> compiler error
 * 
 * Be careful when using overloaded functions and default arguments
 * Ex1:
 * void print(int num = 50);
 * void print(double num);
 * print(); //int -> 50  -> OK
 * But Ex2: compiler error
 * void print(int num = 50);
 * void print(double num = 50.5);
 * print(); // which one ? --> compiler error
 * 
 * */

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

void print(int num);
void print(double num);
void print(string s);
void print(string s, string t);
void print(vector<string> v);

void print(int num)
{
    cout << "Print int: " << num << endl;
}

void print(double num)
{
    cout << "Print double: " << num << endl;
}

void print(string s)
{
    cout << "Print string: " << s << endl;
}

void print(string s, string t)
{
    cout << "Print 2 strings: " << s << " and " << t << endl;
}

void print(vector<string> v)
{
    cout << "Print vector of strings: ";
    for (auto s : v)
    {
        cout << s + " ";
    }
    cout << endl;
}

int main()
{
	print(100); //int
    print('A'); // character is always promoted to int should print 65 ASCII ('A')

    print(123.5); //double
    print(123.3F); //Float is promoted to double

    print("C-style string"); // C-style string is converted to C++ string

    string s{"C++ string"};
    print(s); // C++ string

    print("C-style string", s); // First argument is converted to C++ string

    vector<string> three_stooges{"Larry", "Moe", "Curly"};
    print(three_stooges);

	return 0;
}
