/*
 * @File Jaccard.cxx
 *
 * @Date 02-11-2012
 *
 */

#include <algorithm>    // min

#include <cstring>      // strlen

#include "Jaccard.h"

#include <iostream>
using namespace std;
float nsUtil::Jaccard (const char * A, const char * B) throw ()
{
    unsigned M00 (0), M11 (0), n(0), diff;
    bool isA, isB;
    for (unsigned i(0); i < std::min(strlen(A), strlen(B)); ++i)
    {
        ++n;
        for (unsigned j(0); j < 8; ++j)
        {
            isA = (1 & (A[i] >> j));
            isB = (1 & (B[i] >> j));
            M11 +=  isA &   isB;
            M00 += !isA && !isB;
        }
    }
    n <<= 3;

    return (diff = n - M00) ? M11/float(diff) : 0;

} // Jaccard()
