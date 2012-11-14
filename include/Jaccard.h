/*
 * @File Jaccard.h
 *
 * @Date 02-11-2012
 *
 */
#ifndef __JACCARD_H__
#define __JACCARD_H__

#include "CLink.h"

namespace nsUtil
{
    template <class T>
    float Jaccard (nsSdD::CLink<T> * A, nsSdD::CLink<T> * B) throw ();

} // namespace nsUtil

#include "Jaccard.hxx"

#endif /*__JACCARD_H__ */
