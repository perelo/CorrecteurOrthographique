/*
 * @File MathUtil.cxx
 *
 */
#include "MathUtil.h"

unsigned long nsUtil::Factorielle (const unsigned n)
{
    if (0 == n) return 1;
    return n * Factorielle(n-1);

} // Factorielle()

unsigned long nsUtil::ProchainePuissanceDeDix (const unsigned n)
{
    unsigned long i;
    for (i = 10; n / i > 1; i *= 10);
    return i;

} // ProchainePuissanceDeDix()
