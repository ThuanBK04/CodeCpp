#include <iostream>
#include <cstring>
#include "Mystring.h"

// No-args constructor
Mystring::Mystring()
    :str{nullptr}
{
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char* s)
    :str{nullptr}
{
    if (nullptr == s)
    {
        str = new char[1];
        *str = '\0';
    }
    else
    {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
}

// Copy constructor
Mystring::Mystring(const Mystring &source)
    :str{nullptr}
{
    str = new char[strlen(source.str) + 1];
    strcpy(str, source.str);
}

// Move constructor
Mystring::Mystring(Mystring &&source)
    :str{source.str}
{
    source.str = nullptr;
}

// Destructor
Mystring::~Mystring()
{
    delete [] str;
}

// Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs)
{
    if (this == &rhs)
        return *this;
    delete [] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

// Move assignment
Mystring &Mystring::operator=(Mystring &&rhs)
{
    if (this == &rhs)
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

void Mystring::display () const
{
    std::cout << str << " : " << get_lenght() << std::endl;
}

// Getters
int Mystring::get_lenght () const
{
    return strlen(str);
}

char *Mystring::get_str() const
{
    return str;
}

// Overloaded insertion operator
std::ostream &operator<<(std::ostream &os, const Mystring &rhs)
{
    os << rhs.str;
    return os;
}

std::istream &operator>>(std::istream &is, Mystring &rhs)
{
    char* buffer = new char[1000];
    is >> buffer;
    rhs = Mystring{buffer};
    delete [] buffer;
    return is;
}

// Overloaded operator member methods
// make lowercase
Mystring Mystring::operator-() const
{
    char * buff = new char[std::strlen(str) + 1];

    for (size_t i = 0; i < std::strlen(str); i++)
    {
        buff[i] = std::tolower(str[i]);
    }

    buff[std::strlen(str)] = '\0';

    Mystring temp{buff};
    delete [] buff;
    return temp;
}

// concatenate
Mystring Mystring::operator+(const Mystring &rhs) const
{
    char * buffer = new char [std::strlen(str) + std::strlen(rhs.str) +1];
    std::strcpy(buffer, str);
    std::strcat(buffer, rhs.str);
    Mystring temp{buffer};
    delete [] buffer;
    return temp;
}

//equal
bool Mystring::operator==(const Mystring &rhs) const
{
    return (std::strcmp(str, rhs.str) == 0);
}

// not equal
bool Mystring::operator!=(const Mystring &rhs) const
{
    return (std::strcmp(str, rhs.str) != 0);
}

// less than
bool Mystring::operator<(const Mystring &rhs) const
{
    return (std::strcmp(str, rhs.str) < 0);
}

// greater than
bool Mystring::operator>(const Mystring &rhs) const
{
    return (std::strcmp(str, rhs.str) > 0);
}

// concat and assign
Mystring &Mystring::operator+=(const Mystring &rhs)
{
    *this = *this + rhs.str;
    return *this;
}

// s1 = s2 * 3;  repeat s2 n times
Mystring Mystring::operator*(int n) const
{
    Mystring temp;
    for (int i = 0; i < n; i++)
    {
        temp = temp + *this;
    }
    return temp;
}

// s1 *= 3;   s1 = s1 * 3;
Mystring &Mystring::operator*=(int n)
{
    *this = *this * n;
    return *this;
}

// pre-increment    ++s1
Mystring &Mystring::operator++()
{
    for (int i = 0; i < std::strlen(str); i++)
    {
        str[i] = std::toupper(str[i]);
    }
    return *this;
}

// post-increment   s1++;
Mystring Mystring::operator++(int)
{
    Mystring temp (*this);
    operator++();
    return temp;
}