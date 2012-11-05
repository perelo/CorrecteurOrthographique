/*
 * @File Correcteur.h
 *
 * @Date 01-11-2012
 *
 */
#ifndef __CORRECTEUR_H__
#define __CORRECTEUR_H__

#include <vector>
#include <string>

#include "CHashMap.h"
#include "CLink.h"
#include "IComp.h"

namespace nsCorr
{
    typedef nsSdD::CHashMap<std::string, std::string> DicoMap_t;
    typedef nsSdD::CHashMap<std::string, nsSdD::CLink<std::string>*> TrigMap_t;
    typedef nsSdD::CHashMap<std::string, unsigned>                   StrCpt_t;

    void AjouterDelimiteur (std::string & Mot)                  throw ();
    nsSdD::CLink<std::string> * GetTrigrammes (const std::string & Mot)
                                                                    throw ();

    void RemplirDicoAvecFichier (const std::string & PathDico,
                                 DicoMap_t & Dico,
                                 TrigMap_t & Trig) throw ();

    /*
     * renvoie 0 si le mot est present dans le dictionnaire, 1 sinon
     * et rempli VProp de propositions
     */
    int CorrigerMot (const std::string & Mot,
                     const DicoMap_t & Dico,
                     const TrigMap_t & DicoTrig,
                     std::vector<std::string> & VProp);

    class CompJaccard : public nsUtil::IComp <std::string>
    {
      private :
        const std::string Mot;

      public :
        CompJaccard (const std::string & Mot)                  throw ();
        virtual ~CompJaccard (void)                            throw ();
        virtual bool operator () (const std::string & A,
                                  const std::string & B) const throw ();

    }; // CompJaccard

    class CompLevenshteinC : public nsUtil::IComp <std::string>
    {
      private :
        const std::string Mot;

      public :
        CompLevenshteinC (const std::string & Mot)             throw ();
        virtual ~CompLevenshteinC (void)                       throw ();
        virtual bool operator () (const std::string & A,
                                  const std::string & B) const throw ();

    }; // CompLevenshteinC

} // namespace nsCorr

#include "Correcteur.hxx"

#endif /* __CORRECTEUR_H__ */
