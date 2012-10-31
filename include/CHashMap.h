/*
 * @File : CHashMap.h
 *
 */
#ifndef __CHASHMAP_H__
#define __CHASHMAP_H__

#include <vector>
#include <utility>      // pair

#include "CLink.h"
#include "IHash.h"

namespace nsSdD
{
    template <class K, class V>
    class CHashMap
    {
      public :
        typedef CLink<std::pair<K, V> >   LinkPair_t;
        typedef std::vector<LinkPair_t *> VLinkPair_t;
        typedef CLink<std::pair<K, V> > * Iter_t;
        typedef nsUtil::IHash<K>          Hashor_t;

      private :
        static const float s_LoadFactor;

        unsigned m_NbElem;
        VLinkPair_t m_V;
        Hashor_t * m_Hashor; // ptr car polymorphisme dans le constructeur

//        void EnsureCapacity (void)                                  throw ();

      public :
        CHashMap (Hashor_t * Hashor, const unsigned Cap)            throw ();
//        CHashMap (Hashor_t * Hashor)                                throw ();
        virtual ~CHashMap (void)                                    throw ();

        const unsigned & GetNbElem   (void)                   const throw ();
        unsigned         GetCapacity (void)                   const throw ();
        void FillNbEntree (std::vector<unsigned> & VNbEntree) const throw ();

        const V & Get (const K & Key)                         const throw ();
        void Put (const K & Key, const V & Value)                   throw ();

        Iter_t begin ()                                       const throw ();
        Iter_t end   ()                                       const throw ();

    }; // CHashMap

} // namespace nsSdD

#include "CHashMap.hxx"

#endif /* __CHASHMAP_H__ */
