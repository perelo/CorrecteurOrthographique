/*
 * @File : CLink.hxx
 *
 */
#ifndef __CLINK_HXX__
#define __CLINK_HXX__

#include "CLink.h"

#define TEMPL    template <class T>
#define TEMPLINL TEMPL inline

#define LINK nsSdD::CLink<T>

TEMPLINL
LINK::CLink (const T &    Info    /* = T() */,
             const PtrL_t Suivant /* = 0 */) throw ()
 : m_Info (Info), m_Suivant (Suivant) {}

TEMPLINL LINK::~CLink (void) throw ()
{
    // detruire la liste recursivement
    delete GetSuivant();

} // ~CLink

TEMPLINL
T & LINK::GetInfo (void) const throw () { return m_Info; }

TEMPLINL
T & LINK::GetInfo (void)       throw () { return m_Info; }

TEMPLINL
LINK * LINK::GetSuivant (void) const throw () { return m_Suivant; }

TEMPLINL
void LINK::SetInfo    (const T & Info)      throw () { m_Info = Info; }

TEMPLINL
void LINK::SetSuivant (const PtrL_t Suivant) throw () { m_Suivant = Suivant; }

TEMPLINL
LINK * LINK::InsereApres (PtrL_t NewElem) throw ()
{
    NewElem->SetSuivant(this->GetSuivant());
    this->SetSuivant(NewElem);

    return NewElem;

} // InsereApres()

TEMPLINL
LINK * LINK::SupprimeSuivant (PtrL_t Elem) throw ()
{
    PtrL_t Suivant = Elem->GetSuivant();
    Elem->SetSuivant(Suivant->GetSuivant());

    return Suivant;

} // Supprime()

#undef LINK
#undef TEMPLINL
#undef TEMPL

#endif /* __CLINK_HXX__ */
