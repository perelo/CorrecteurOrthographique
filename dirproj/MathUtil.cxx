/*
 * @File MathUtil.cxx
 *
 * @Date 26-10-2012
 *
 */

#include "MathUtil.h"

unsigned long nsUtil::Factorielle (const unsigned n)
{
    if (0 == n) return 1;
    return n * Factorielle(n-1);

} // Factorielle()
