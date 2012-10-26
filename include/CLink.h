/*
 * @File : CLink.h
 *
 */
#include <string>

#ifndef __CLINK_H__
#define __CLINK_H__

namespace nsSdD
{
    class CLink
    {
      public :
        typedef CLink * PtrL_t;

      protected :
        std::string m_Str;
        PtrL_t      m_Suivant;

      private :
        CLink (const CLink &);
        CLink & operator = (const CLink &);

      public :
        CLink (const std::string & Str     = std::string(),
               const PtrL_t        Suivant = 0)        throw();
        ~CLink (void)                                  throw();

        std::string GetStr     (void) const            throw();
        PtrL_t      GetSuivant (void) const            throw();

        void SetStr     (const std::string & Str)      throw();
        void SetSuivant (const PtrL_t Suivant)         throw();

        PtrL_t InsereApres     (PtrL_t NewElem)        throw();
        PtrL_t SupprimeSuivant (PtrL_t Elem)           throw();

    }; // CLink

} // namespace nsSdD

#include "CLink.hxx"

#endif /* __CLINK_H__ */
