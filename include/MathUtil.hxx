/*
 * @File MathUtil.hxx
 *
 * @Date 26-10-2012
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

#endif /* __MATHUTIL_HXX__ */
