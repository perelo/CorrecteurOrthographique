/*
 * @File CHashMap.h
 *
 * @Date 26-10-2012
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
        typedef K                         Key_t;
        typedef V                         Value_t;
        typedef std::pair<K, V>           Entry_t;
        typedef CLink<Entry_t>            LinkPair_t;
        typedef std::vector<LinkPair_t *> VLinkPair_t;
        typedef std::vector<Key_t>        VKeys_t;
        typedef nsUtil::IHash<K>          Hashor_t;
//        typedef CLink<std::pair<K, V> > * Iter_t;

      private :
        static const float s_LoadFactor;

        unsigned m_NbElem;
        VLinkPair_t m_V;
        Hashor_t * m_Hashor; // ptr car polymorphisme dans le constructeur
        VKeys_t m_Keys;

//        void EnsureCapacity (void)                                  throw ();

      public :
        CHashMap (Hashor_t * Hashor, const unsigned Cap)            throw ();
//        CHashMap (Hashor_t * Hashor)                                throw ();
        ~CHashMap (void)                                            throw ();

        unsigned        GetNbElem   (void)                    const throw ();
        unsigned        GetCapacity (void)                    const throw ();
        const VKeys_t & GetKeys     (void)                    const throw ();
        void FillNbEntree (std::vector<unsigned> & VNbEntree) const throw ();

        Value_t & operator [] (const Key_t & Key)                   throw ();
        const Entry_t * Find  (const Key_t & Key)             const throw ();

        // TODO remove, FOR DEBUG PURPOSE ONLY
        VLinkPair_t & GetV (void) throw () { return m_V; }

//        Iter_t begin ()                                       const throw ();
//        Iter_t end   ()                                       const throw ();

    }; // CHashMap

} // namespace nsSdD

#include "CHashMap.hxx"

#endif /* __CHASHMAP_H__ */
