#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring
{
private:
    char *str; // pointer to a char[] that holds a C-style string
public:
    Mystring(); // no-args contructors
    Mystring(const char *s); //overloaded contructors
    Mystring(const Mystring &source); //copy contructors
    ~Mystring();
    Mystring &operator=(const Mystring &rhs); // Copy assignment
    void display() const;
    int get_length() const;
    const char *get_str() const;
};

#endif // _MYSTRING_H_
