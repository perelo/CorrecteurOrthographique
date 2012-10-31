/*
 * @File : CHashMap.hxx
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
MAP::~CHashMap () throw () {}

TEMPLINL
const unsigned & MAP::GetNbElem (void) const throw ()
{
    return m_NbElem;

} // GetNbElem()

TEMPLINL
unsigned MAP::GetCapacity (void) const throw ()
{
    return m_V.size();

} // GetCapacity()

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
void MAP::Put (const K & Key, const V & Value) throw ()
{
//    EnsureCapacity();

    unsigned H ((*m_Hashor)(Key, GetCapacity()));
    LinkPair_t * Prec = 0;

    for (LinkPair_t * Elem (m_V[H]); Elem; Prec = Elem,
                                           Elem = Elem->GetSuivant())
        if (Value == Elem->GetInfo().second) return;

    if (Prec)
        Prec->SetSuivant(new LinkPair_t(make_pair(Key, Value)));
    else
        m_V[H] = new LinkPair_t(make_pair(Key, Value));

    ++m_NbElem;

} // Put()

TEMPL
const V & MAP::Get (const K & Key) const throw ()
{
    LinkPair_t * Elem = m_V[m_Hashor(Key, GetCapacity())];
    for (; Elem && Key != Elem->GetInfo().first; Elem = Elem->GetSuivant());

    return (Elem ? Elem->GetInfo().second : V());

} // Get()

TEMPL
typename MAP::Iter_t MAP::begin () const throw ()
{
    for (typename VLinkPair_t::const_iterator i (m_V.begin());
                                                        i < m_V.end(); ++i)
        if (*i) return *i;

    return 0;

} // begin()

TEMPL
typename MAP::Iter_t MAP::end () const throw ()
{
    for (typename VLinkPair_t::const_reverse_iterator i (m_V.rbegin());
                                                        i < m_V.rend(); ++i)
    {
        if (*i)
        {
            LinkPair_t * p;
            for (p = *i; p != 0; ++i);
            return p;
        }
    }

    return 0;

} // end()

#undef MAP
#undef TEMPLINL
#undef TEMPL

#endif /* __CHASHMAP_HXX__ */
