#ifndef _I_PRINTABLE_H_
#define _I_PRINTABLE_H_
#include <iostream>

class I_Printable
{
/*

The second parameter is a const I printable.
It's really important that this is an I printable, not an account, not anything else.
Since an account will be derived from an I printable,
everything in that hierarchy will also be an eye principle and conform to this interface.

*/
    friend std::ostream &operator<<(std::ostream &os, const I_Printable &obj);
public:
    virtual void print (std::ostream &os) const = 0;
    virtual ~I_Printable() = default;
};

#endif // _I_PRINTABLE_H_
