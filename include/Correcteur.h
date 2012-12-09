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
    typedef nsSdD::CHashMap<std::string, int>                        DicoMap_t;
    typedef nsSdD::CHashMap<std::string, nsSdD::CLink<std::string>*> TrigMap_t;
    typedef nsSdD::CHashMap<std::string, unsigned>                   StrCpt_t;

    const float CoefNbTrigrammesCommuns = 0.5;
    const float CoefJaccardMin          = 0.2;

    void AjouterDelimiteur (std::string & Mot)                      throw ();
    nsSdD::CLink<std::string> * GetTrigrammes (const std::string & Mot)
                                                                    throw ();

    void RemplirDicosAvecFichier (const std::string & PathDico,
                                  DicoMap_t & Dico,
                                  TrigMap_t & DicoTrigs) throw ();

    /*
     * renvoie 0 si le mot est present dans le dictionnaire, 1 sinon
     * et rempli VProp de propositions
     */
    void CorrigerMot (const std::string & Mot,
                      const DicoMap_t & Dico,
                      const TrigMap_t & DicoTrigs,
                      std::vector<std::string> & VProp) throw ();

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
