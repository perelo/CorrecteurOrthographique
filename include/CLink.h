/*
 * @File CLink.h
 *
 * @Date 26-10-2012
 *
 */
#ifndef __CLINK_H__
#define __CLINK_H__

namespace nsSdD
{
    template <class T>
    class CLink
    {
      public :
        typedef CLink<T> * PtrL_t;

      protected :
        T      m_Info;
        PtrL_t m_Suivant;

      private :
        CLink (const CLink &);
        CLink & operator = (const CLink &);

      public :
        CLink (const T & Info       = T(),
               const PtrL_t Suivant = 0)        throw ();
        ~CLink (void)                           throw ();

        const T & GetInfo (void) const          throw ();
              T & GetInfo (void)                throw ();
        PtrL_t GetSuivant (void) const          throw ();

        void SetInfo    (const T & Info)        throw ();
        void SetSuivant (const PtrL_t Suivant)  throw ();

    }; // CLink

} // namespace nsSdD

#include "CLink.hxx"

#endif /* __CLINK_H__ */
