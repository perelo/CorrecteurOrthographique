/*
 * @File : CLink.hxx
 *
 */
#include <string>

#ifndef __CLINK_HXX__
#define __CLINK_HXX__

#include "CLink.h"

#define LINK nsSdD::CLink

inline
LINK::CLink (const std::string & Str     /* = std::string() */,
             const PtrL_t        Suivant /* = 0 */)        throw()
 : m_Str (Str), m_Suivant (Suivant) {}

inline LINK::~CLink (void) throw()
{
    // detruire la liste recursivement
    delete GetSuivant();

} // ~CLink

inline
std::string LINK::GetStr (void) const throw() { return m_Str; }

inline
LINK * LINK::GetSuivant (void) const throw() { return m_Suivant; }

inline
void LINK::SetStr (const std::string & Str) throw()
{
    m_Str = Str;

} // SetStr()

inline
void LINK::SetSuivant (const PtrL_t Suivant) throw()
{
    m_Suivant = Suivant;

} // SetSuivant()

inline
LINK * LINK::InsereApres (PtrL_t NewElem) throw()
{
    NewElem->SetSuivant(this->GetSuivant());
    this->SetSuivant(NewElem);

    return NewElem;

} // InsereApres()

inline
LINK * LINK::SupprimeSuivant (PtrL_t Elem) throw()
{
    PtrL_t Suivant = Elem->GetSuivant();
    Elem->SetSuivant(Suivant->GetSuivant());

    return Suivant;

} // Supprime()

#endif /* __CLINK_HXX__ */
