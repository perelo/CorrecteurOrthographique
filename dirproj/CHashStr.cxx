/*
 * @File CHashStr.cxx
 *
 * @Date 30-10-2012
 *
 */

#include <string>

#include "CHashStr.h"

using namespace std;

#define HSTR nsUtil::CHashStr

#include <iostream>
using std::cout;
using std::endl;
unsigned HSTR::operator () (const string & Str, const unsigned Cap)
                                                                const throw ()
{
    unsigned Hash (0);
    for (unsigned i(0); i < Str.size(); ++i)
        Hash = (Hash * 31 + Str[i]) % Cap;

    return Hash;

} // Hash()

#undef HSTR
