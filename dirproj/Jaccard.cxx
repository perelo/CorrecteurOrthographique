/*
 * @File Jaccard.cxx
 *
 * @Date 02-11-2012
 *
 */

#include "Jaccard.h"

float nsUtil::Jaccard (const int A, const int B) throw ()
{
    unsigned M00 (0), M11 (0), n(0), diff;
    bool isA, isB;
    for (unsigned i(0); i < sizeof(int); ++i)
    {
        ++n;
        for (unsigned j(0); j < 8; ++j)
        {
            isA = (1 & (A >> j));
            isB = (1 & (B >> j));
            M11 +=  isA &   isB;
            M00 += !isA && !isB;
        }
    }
    n <<= 3;

    return (diff = n - M00) ? M11/float(diff) : 0;

} // Jaccard()
