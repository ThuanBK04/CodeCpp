#ifndef MYSTRING_H
#define MYSTRING_H

class Mystring
{
    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
    friend std::istream &operator>>(std::istream &is, Mystring &rhs);
private:
    char *str; // pointer to a char[] that holds a C-style string
public:
    Mystring(); // No-args constructor
    Mystring(const char *s); // Overloaded constructor
    Mystring(const Mystring &source); // Copy constructor
    Mystring(Mystring &&source); // Move constructor
    ~Mystring();

    Mystring &operator=(const Mystring &rhs); // Copy assignment
    Mystring &operator=(Mystring &&rhs); // Move assignment

    void display() const;

    int get_length() const; // getters
    const char *get_str() const;
};

#endif // MYSTRING_H
