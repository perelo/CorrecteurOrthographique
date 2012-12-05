/*
 * @File CHashMap.hxx
 *
 * @Date 26-10-2012
 *
 */
#ifndef __CHASHMAP_HXX__
#define __CHASHMAP_HXX__

#include <string>
#include <vector>
#include <utility>      // pair

#include "CHashMap.h"
#include "CLink.h"
#include "MathUtil.h"   // Poisson(), ProchainNombreRond()

#define TEMPL    template <class K, class V>
#define TEMPLINL TEMPL inline

#define MAP nsSdD::CHashMap<K, V>

TEMPL
const float MAP::s_LoadFactor = 0.75;

TEMPL
const unsigned MAP::s_DfltInitialCapacity = 16;

TEMPLINL
MAP::CHashMap (Hashor_t * Hashor,
               const unsigned Cap /* = s_DfltInitialCapacity*/) throw ()
 : m_NbElem (0), m_Threshold (Cap * s_LoadFactor), m_V (Cap)
{
    m_Hashor = Hashor;
}

TEMPLINL
MAP::~CHashMap () throw ()
{
    for (unsigned i(0); i < GetCapacity(); ++i)
        delete m_V[i];
}

TEMPLINL
unsigned MAP::GetNbElem (void) const throw ()
{
    return m_NbElem;

} // GetNbElem()

TEMPLINL
unsigned MAP::GetCapacity (void) const throw ()
{
    return m_V.size();

} // GetCapacity()

TEMPL
void MAP::Resize (unsigned NewCap) throw ()
{
    VLinkPair_t NewV (NewCap);

    // rehash everything
    for (size_t i(0); i < GetCapacity(); ++i)
    {
        for (LinkPair_t * LPair (m_V[i]); LPair; )
        {
            LinkPair_t * NewLPair (LPair);
            LPair = LPair->GetSuivant();
            unsigned Hash ((*m_Hashor)(NewLPair->GetInfo().first, NewCap));
            NewLPair->SetSuivant(NewV[Hash]);
            NewV[Hash] = NewLPair;
        }
    }

    m_V = NewV;
    m_Threshold = GetCapacity() * s_LoadFactor;

} // Resize()

TEMPL
void MAP::FillNbEntree (std::vector<unsigned> & VNbEntree) const throw ()
{
    /*
     * On sait que l'occupation maximale d'une boite
     * respecte la loi de poisson
     */
    unsigned KMax;
    const float Alpha = float(GetNbElem()) / GetCapacity();
    for (KMax = 0; GetCapacity() * nsUtil::Poisson(Alpha, KMax++) > 0.5; );

    for (unsigned i(0); i < KMax; ++i) VNbEntree.push_back(0);

    for (unsigned i(0); i < GetCapacity(); ++i)
    {
        unsigned n (0);
        for (LinkPair_t * p (m_V[i]);
             p != 0;
             p = p->GetSuivant()) ++n;
        ++VNbEntree[n];
    }

} // FillNbEntree()

TEMPL
typename MAP::Value_t & MAP::operator [] (const Key_t & Key) throw ()
{
    unsigned H ((*m_Hashor)(Key, GetCapacity()));

    for (LinkPair_t * Elem (m_V[H]); Elem != 0; Elem = Elem->GetSuivant())
        if (Elem->GetInfo().first == Key)
            return Elem->GetInfo().second;

    // pas d'elements a l'indice Key, on le cree, initialise par defaut
    m_V[H] = new LinkPair_t(make_pair(Key, Value_t()), m_V[H]);

    if (++m_NbElem > m_Threshold)
    {
        Resize(GetCapacity() << 1);
        // compute the new hash (cuz capacity have changed)
        H = (*m_Hashor)(Key, GetCapacity());
    }

    return m_V[H]->GetInfo().second;

} // operator[]()

TEMPL
const typename MAP::Entry_t * MAP::Find (const Key_t & Key) const throw ()
{
    return const_cast<MAP*>(this)->Find(Key);

} // Find()

TEMPL
typename MAP::Entry_t * MAP::Find (const Key_t & Key) throw ()
{
    unsigned H ((*m_Hashor)(Key, GetCapacity()));

    for (LinkPair_t * Elem (m_V[H]); Elem != 0; Elem = Elem->GetSuivant())
        if (Elem->GetInfo().first == Key)
            return &Elem->GetInfo();

    return 0;

} // Find()

TEMPLINL
MAP::iterator::iterator (CHashMap<K, V> * Map, unsigned Pos,
                         CLink<Entry_t> * Iter) throw ()
 : m_Map (Map), m_Pos (Pos), m_Iter (Iter) {}

TEMPL
typename MAP::iterator MAP::begin () throw ()
{
    for (unsigned i(0); i < m_V.size(); ++i)
        if (m_V[i])
            return iterator(this, i, m_V[i]);

    return end();

} // begin()

TEMPLINL
typename MAP::iterator MAP::end () throw ()
{
    return iterator(0, 0, 0);

} // end()

TEMPL
typename MAP::iterator & MAP::iterator::operator ++ (void) throw ()
{
    if (m_Iter->GetSuivant())
        m_Iter = m_Iter->GetSuivant();
    else
    {
        for (++m_Pos; m_Pos < m_Map->m_V.size(); ++m_Pos)
        {
            if (m_Map->m_V[m_Pos])
            {
                m_Iter = m_Map->m_V[m_Pos];
                break;
            }
        }
    }
    if (m_Pos >= m_Map->m_V.size())
        *this = m_Map->end();

    return *this;

} // operator ++()

TEMPLINL
typename MAP::iterator MAP::iterator::operator ++ (int)  throw ()
{
    iterator Copie (*this);
    ++(*this);
    return Copie;

} // operator ++(int)

TEMPLINL
const typename MAP::Entry_t & MAP::iterator::operator *  () const throw ()
{
    return m_Iter->GetInfo();

} // operator *()

TEMPLINL
const typename MAP::Entry_t * MAP::iterator::operator -> () const throw ()
{
    return & operator * ();

} // operator ->()

TEMPLINL
bool MAP::iterator::operator == (const iterator & It) throw ()
{
    return this->m_Iter == It.m_Iter;

} // operator ==()

TEMPLINL
bool MAP::iterator::operator != (const iterator & It) throw ()
{
    return ! (*this == It);

} // operator !=()

#undef MAP
#undef TEMPLINL
#undef TEMPL

#endif /* __CHASHMAP_HXX__ */
