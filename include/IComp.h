/*
 * @File IComp.h
 *
 * @Date 03-11-2012
 *
 */
#ifndef __ICOMP_H__
#define __ICOMP_H__

namespace nsUtil
{
    template <class T>
    class IComp
    {
      public :
        virtual ~IComp (void)                                     throw ();
        virtual bool operator () (const T & A, const T & B) const throw () = 0;

    }; // IComp

} // namespace nsUtil

#include "IComp.hxx"

#endif /* __ICOMP_H__ */
