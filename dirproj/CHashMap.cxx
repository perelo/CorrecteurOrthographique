/*
 * @File : CHashMap.cxx
 *
 */
#include <string>
#include <vector>

#include "CHashMap.h"

using namespace std;

#define MAP nsSdD::CHashMap

const float MAP::Alpha = 0.5;

unsigned MAP::Hash (const string & k) const throw()
{
    unsigned Hash (0);
    for (unsigned i(0); i < k.size(); ++i)
        Hash = (Hash * 31 + k[i]) % V.size();

    return Hash;

} // Hash()

#undef MAP
