/*
 * @File : CHashMap.h
 *
 */
#include <string>
#include <vector>

#ifndef __CHASHMAP_H__
#define __CHASHMAP_H__

#include "CLink.h"

namespace nsSdD
{
    class CHashMap
    {
      private :
        static const float Alpha;
        std::vector<CLink*> V;

        unsigned Hash (const std::string &) const throw();

      public :
        CHashMap (const unsigned NbElem)      throw();
        ~CHashMap (void)                      throw();

        std::string Get (const std::string &) const         throw();
        void Put (const std::string &) throw();

    }; // CHashMap

} // namespace nsSdD

#include "CHashMap.hxx"

#endif /* __CHASHMAP_H__ */

