/*
 * IHash.h
 *
 */
#ifndef __IHASH_H__
#define __IHASH_H__

namespace nsUtil
{
    template <class T>
    class IHash
    {
      public :
        virtual unsigned operator () (const T & ToHash, const unsigned Cap)
                                                            const throw () = 0;
        virtual ~IHash () throw ();

    }; // IHash

} // namespace nsUtil

#include "IHash.hxx"

#endif /* __IHASH_H__ */
