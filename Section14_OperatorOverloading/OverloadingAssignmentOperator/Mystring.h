#ifndef _MY_STRING_H
#define _MY_STRING_H

class Mystring
{
private:
    char *str;      // pointer to a char[] that holds a C-style string
public:
Mystring();                                   // No-args constructor
Mystring(const char *s);                      // Overloaded constructor
Mystring(const Mystring &source);             // Copy constructor
Mystring( Mystring &&source);                 // Move constructor
~Mystring();                                  // Destructor
    
    Mystring &operator=(const Mystring &rhs); // Copy assignment
    Mystring &operator=(Mystring &&rhs);      // Move assignment

    void display() const;

    int get_length() const;                                       // getters
    const char *get_str() const;
};

#endif // _MY_STRING_H
