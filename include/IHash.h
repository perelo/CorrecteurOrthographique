/*
 * @File IHash.h
 *
 * @Date 30-10-2012
 *
 */
#ifndef __IHASH_H__
#define __IHASH_H__

#include <functional>

namespace nsUtil
{
    template <class T>
    class IHash : public std::binary_function <T, T, bool>
    {
      public :
        virtual ~IHash (void)                                     throw ();
        virtual unsigned operator () (const T & ToHash, const unsigned Cap)
                                                            const throw () = 0;

    }; // IHash

} // namespace nsUtil

#include "IHash.hxx"

#endif /* __IHASH_H__ */
