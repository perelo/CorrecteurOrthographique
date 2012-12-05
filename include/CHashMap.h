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
        typedef std::pair<Key_t, Value_t> Entry_t;
        typedef CLink<Entry_t>            LinkPair_t;
        typedef std::vector<LinkPair_t *> VLinkPair_t;
        typedef nsUtil::IHash<Key_t>      Hashor_t;

      private :
        static const float    s_LoadFactor;
        static const unsigned s_DfltInitialCapacity;

        unsigned m_NbElem;
        unsigned m_Threshold;   // if m_NbElem > m_Threshold, resize
        VLinkPair_t m_V;
        Hashor_t * m_Hashor;    // ptr car polymorphisme dans le constructeur

        void Resize (unsigned Cap)                                  throw ();

        CHashMap (const CHashMap &);
        CHashMap & operator = (const CHashMap &);

      public :
        CHashMap (Hashor_t * Hashor,
                  const unsigned Cap = s_DfltInitialCapacity)       throw ();
        ~CHashMap (void)                                            throw ();

        unsigned        GetNbElem   (void)                    const throw ();
        unsigned        GetCapacity (void)                    const throw ();
        void FillNbEntree (std::vector<unsigned> & VNbEntree) const throw ();

        Value_t & operator [] (const Key_t & Key)                   throw ();
        const Entry_t * Find  (const Key_t & Key)             const throw ();
              Entry_t * Find  (const Key_t & Key)                   throw ();


        class iterator
        {
          private :
            friend class CHashMap<Key_t, Value_t>;
            CHashMap<K, V> * m_Map;
            unsigned m_Pos;
            CLink<Entry_t> * m_Iter;

            iterator (CHashMap<Key_t, Value_t> * Map, unsigned Pos,
                      CLink<Entry_t>           * Iter) throw ();

          public :
            iterator & operator ++ (void)              throw ();
            iterator   operator ++ (int)               throw ();
            const Entry_t & operator *  () const       throw ();
            const Entry_t * operator -> () const       throw ();

            bool operator == (const iterator & It)     throw ();
            bool operator != (const iterator & It)     throw ();

        }; // iterator

        iterator begin ()                                           throw ();
        iterator end   ()                                           throw ();

    }; // CHashMap

} // namespace nsSdD

#include "CHashMap.hxx"

#endif /* __CHASHMAP_H__ */
