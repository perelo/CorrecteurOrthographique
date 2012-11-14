/*
 * @File Jaccard.hxx
 *
 * @Date 02-11-2012
 *
 */
#ifndef __JACCARD_HXX__
#define __JACCARD_HXX__

#include "CLink.h"
#include "Jaccard.h"

template <class T>
float nsUtil::Jaccard (nsSdD::CLink<T> * A, nsSdD::CLink<T> * B) throw ()
{
    unsigned TailleA, TailleB, TailleIntersect;
    TailleA = TailleB = TailleIntersect = 0;

    for (nsSdD::CLink<T> * p (A); p != 0; p = p->GetSuivant())
    {
        ++TailleA;
        for (nsSdD::CLink<T> * q (B); q != 0; q = q->GetSuivant())
        {
            ++TailleB;
            if (p->GetInfo() == q->GetInfo())
                ++TailleIntersect;
        }
    }
    TailleB /= TailleA;

    return float(TailleIntersect) / (TailleA + TailleB - TailleIntersect);

} // Jaccard()

#endif /*__JACCARD_HXX__ */
