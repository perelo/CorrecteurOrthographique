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

TEMPLINL
MAP::CHashMap (Hashor_t * Hashor, const unsigned Cap) throw ()
 : m_NbElem (0), m_V (Cap)
{
    m_Hashor = Hashor;
}

//TEMPLINL
//MAP::CHashMap (Hashor_t * Hashor) throw ()
// : m_NbElem (0), m_V (16)
//{
//    m_Hashor = Hashor;
//}

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

TEMPLINL
const typename MAP::VKeys_t & MAP::GetKeys (void) const throw ()
{
    return m_Keys;

} // GetKeys()

//TEMPL
//void MAP::EnsureCapacity (void) throw ()
//{
//    if (m_NbElem+1 < m_V.size() * s_LoadFactor) return;
//
//    // resize and rehash everything
//    VLinkPair_t OldV (m_V.begin(), m_V.end());
//    m_V = VLinkPair_t (nsUtil::ProchainNombreRond(m_NbElem << 1));
//    m_NbElem = 0;
//
//    for (typename VLinkPair_t::iterator i (OldV.begin()); i < OldV.end(); ++i)
//        Put((*i)->GetInfo().first, (*i)->GetInfo().second);
//
//} // EnsureCapacity()

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
    //cout << "[] on " << Key << endl;
    unsigned H ((*m_Hashor)(Key, GetCapacity()));

    for (LinkPair_t * Elem (m_V[H]); Elem != 0; Elem = Elem->GetSuivant())
        if (Elem->GetInfo().first == Key)
            return Elem->GetInfo().second;

    // pas d'elements a l'indice Key, on le cree, initialise par defaut
    m_V[H] = new LinkPair_t(make_pair(Key, Value_t()), m_V[H]);
    m_Keys.push_back(Key);
    ++m_NbElem;

    return m_V[H]->GetInfo().second;

} // operator[]()

TEMPL
const typename MAP::Entry_t * MAP::Find (const Key_t & Key) const throw ()
{
    unsigned H ((*m_Hashor)(Key, GetCapacity()));

    for (LinkPair_t * Elem (m_V[H]); Elem != 0; Elem = Elem->GetSuivant())
        if (Elem->GetInfo().first == Key)
            return &Elem->GetInfo();

    return 0;

} // Find()

// TODO use const Find() pour pas qu'il y ai de code dupplique
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
MAP::iterator::iterator (CHashMap<Key_t, Value_t> * Map,
                         const typename VKeys_t::iterator & It) throw ()
 : VKeys_t::iterator (It), m_Map (Map)
{}

TEMPL
typename MAP::iterator MAP::begin () throw ()
{
    return iterator(this, m_Keys.begin());

} // begin()

TEMPL
typename MAP::iterator MAP::end () throw ()
{
    return iterator(this, m_Keys.end());

} // end()

TEMPLINL
typename MAP::Entry_t & MAP::iterator::operator * () throw ()
{
    return * operator -> ();

} // operator *()

TEMPLINL
typename MAP::Entry_t * MAP::iterator::operator -> () throw ()
{
    // TODO check when Find() returns null
    return (m_Map->Find(   * (typename VKeys_t::iterator(*this))   ));

} // operator ->()

#undef MAP
#undef TEMPLINL
#undef TEMPL

#endif /* __CHASHMAP_HXX__ */
