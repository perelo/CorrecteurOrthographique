/*
 * @File CHashStr.h
 *
 * @Date 30-10-2012
 *
 */
#ifndef __CHASHSTR_H__
#define __CHASHSTR_H__

#include <string>

#include "IHash.h"

namespace nsUtil
{
    class CHashStr : public IHash <std::string>
    {
      public :
        virtual ~CHashStr ()                                         throw ();
        virtual unsigned operator () (const std::string & Str,
                                      const unsigned Cap)      const throw ();

    }; // CHashStr

} // namespace nsUtil

#include "CHashStr.hxx"

#endif /* __CHASHSTR_H__ */
