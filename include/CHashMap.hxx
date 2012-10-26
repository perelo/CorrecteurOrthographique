/*
 * @File : CHashMap.hxx
 *
 */
#include <string>
#include <vector>

#ifndef __CHASHMAP_HXX__
#define __CHASHMAP_HXX__

#include "CHashMap.h"
#include "CLink.h"

#define MAP nsSdD::CHashMap
#define CLINK nsSdD::CLink

inline
MAP::CHashMap (const unsigned NbElem) throw()
 : V (NbElem / Alpha) {}

inline
MAP::~CHashMap () throw() {}

inline
std::string MAP::Get (const std::string & k) const throw()
{
    CLINK * Elem = V[Hash(k)];
    for (; Elem && k != Elem->GetStr(); Elem = Elem->GetSuivant());

    return (Elem ? Elem->GetStr() : std::string());

} // Get()

inline
void MAP::Put (const std::string & v) throw()
{
    unsigned H (Hash(v));
    CLINK * Prec = 0;
    CLINK * Elem = V[H];

    for (; Elem; Prec = Elem, Elem = Elem->GetSuivant())
        if (v == Elem->GetStr()) return;

    if (Prec)
        Prec->SetSuivant(new CLINK(v));
    else
        V[H] = new CLINK(v);

} // Put()

#endif /* __CHASHMAP_HXX__ */
