/*
 * CHashStr.h
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
        virtual unsigned operator () (const std::string & Str,
                                      const unsigned Cap)      const throw ();
        virtual ~CHashStr ()                                         throw ();

    }; // CHashStr

} // namespace nsUtil

#include "CHashStr.hxx"

#endif /* __CHASHSTR_H__ */
