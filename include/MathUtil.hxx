/*
 * @File MathUtil.hxx
 *
 */
#ifndef __MATHUTIL_HXX__
#define __MATHUTIL_HXX__

#include <cmath>

inline
float nsUtil::Poisson (const float lambda, const unsigned k)
{
    return std::exp(-lambda)*exp(log(lambda)*k) / Factorielle(k);

} // Poisson()

inline
unsigned long nsUtil::ProchainNombreRond (const unsigned n)
{
    unsigned long Dix (ProchainePuissanceDeDix(n) / 10);
    return (n / Dix)*Dix + Dix;

} // ProchainNombreRond()

#endif /* __MATHUTIL_HXX__ */
