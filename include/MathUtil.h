/*
 * @File MathUtil.h
 *
 */
#ifndef __MATHUTIL_H__
#define __MATHUTIL_H__

namespace nsUtil
{
    float         Poisson (const float lambda, const unsigned k);
    unsigned long Factorielle (const unsigned n);
    unsigned long ProchainePuissanceDeDix (const unsigned n);
    unsigned long ProchainNombreRond (const unsigned n);

} // namespace nsUtil

#include "MathUtil.hxx"

#endif /* __MATHUTIL_H__ */
