#include <cstring>
#include <iostream>
#include "Mystring.h"

Mystring::Mystring()
    :str{nullptr}
{
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
//Checking to see if by any chance somebody sent a null pointer here.
//If they did, I'm just going to create an empty string. I'm just going to double check that just to be safe.
//Normally, this else is going to execute. And I'll show you what's going on here.
Mystring::Mystring (const char *s)
    :str{nullptr}
{
    if (s == nullptr)
    {
        str = new char[1];
        *str = '\0';
    }
    else
    {
        // Figure out what's the length of s and add 1 to it because I need an extra character for that terminator.
        // Ex: "Hello" -> strlen = 5 -> need to allocate a memory which can contain 6 chars
        str = new char[std::strlen(s) + 1];
        std::strcpy(str, s);
    }
}

// Copy constructor
Mystring::Mystring(const Mystring &source)
    :str{nullptr}
{
    str = new char[strlen(source.str) + 1];
    std::strcpy(str, source.str);
}

Mystring::~Mystring()
{}

void Mystring::display() const
{
    std::cout << str << " : " << get_length() << std::endl;
}

int Mystring::get_length() const
{
    return std::strlen(str);
}

const char *Mystring::get_str() const
{
    return str;
}