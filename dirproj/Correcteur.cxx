/*
 * @File Correcteur.cxx
 *
 * @Date 01-11-2012
 *
 */

#include <vector>
#include <string>
#include <fstream>
#include <algorithm>    // sort
#include <limits>       // epsilon

#include "Correcteur.h"
#include "CHashMap.h"
#include "CLink.h"
#include <cmath>        // abs

#include "CHashStr.h"
#include "Levenshtein.h"
#include "Jaccard.h"

using namespace std;
using namespace nsSdD;      // CLink
using namespace nsUtil;     // Jaccard, Levenshtein

#define LINKSTR CLink<string>

LINKSTR * nsCorr::GetTrigrammes (const string & Mot) throw ()
{
    string MotDelim (Mot);
    AjouterDelimiteur (MotDelim);

    LINKSTR * TrigList = 0;
    for (size_t i (0); i < MotDelim.size() - 2; ++i)
        TrigList = new LINKSTR(string(MotDelim, i, 3), TrigList);

    return TrigList;

} // GetTrigrammes()

void nsCorr::RemplirDicosAvecFichier (const string & PathDico,
                                      DicoMap_t & Dico,
                                      TrigMap_t & MotToTrigs,
                                      TrigMap_t & TrigToMots) throw ()
{
    ifstream is (PathDico.c_str());
    if (!is)
    {
        //cerr << "Impossible d'ouvrir le fichier" << endl;
        is.close();
        return;
    }

    for (string Mot; getline(is, Mot); )
    {
        Dico[Mot] = Mot;

        for (LINKSTR * Trig = MotToTrigs[Mot] = GetTrigrammes(Mot);
             Trig;
             Trig = Trig->GetSuivant())
            TrigToMots[Trig->GetInfo()] =
                                    new LINKSTR(Mot, TrigToMots[Trig->GetInfo()]);
            // TODO modifier pour qu'on ne fasse qu'un appel a [] (ici, 2x hash)

    }

    is.close();

} // RemplirDicoAvecFichier()

int nsCorr::CorrigerMot (const string & Mot,
                         const DicoMap_t & Dico,
                         const TrigMap_t & MotToTrigs,
                         const TrigMap_t & TrigToMots,
                         vector<string> & VProp)
{
    if (Dico.Find(Mot)) return 0;

    nsUtil::CHashStr Hashor;
    // Cpt["abc"] : nombre de trigrammes commun entre "abc" et Mot
    StrCpt_t Cpt (&Hashor, 20000); // TODO map qui aug sa cap auto
    unsigned MaxOcc (0);
    LINKSTR * Trig;
    for (Trig = GetTrigrammes(Mot); Trig != 0; Trig = Trig->GetSuivant())
    {
        const TrigMap_t::Entry_t * ETrig = TrigToMots.Find(Trig->GetInfo());
        if (! ETrig) continue;  // aucun mot ne contient ce trigramme

        for (LINKSTR * MotTrigCommun (ETrig->second);
             MotTrigCommun != 0;
             MotTrigCommun = MotTrigCommun->GetSuivant())
            if (++Cpt[MotTrigCommun->GetInfo()] > MaxOcc) ++MaxOcc;
    }
    delete Trig;

    VProp.empty();

    for (StrCpt_t::iterator It (Cpt.begin()); It < Cpt.end(); ++It)
    {
        if (It->second == MaxOcc /*&&
            Jaccard(E.first.c_str(), Mot.c_str()) > 0.2*/)
            VProp.push_back(It->first);
    }

    sort(VProp.begin(), VProp.end(), CompJaccard(Mot));
    // TODO faire quelque chose

    sort(VProp.begin(), VProp.end(), CompLevenshteinC(Mot));
    if (VProp.size() > 10)
        VProp.erase(VProp.begin(), VProp.end() - 10);

    return 1;
}

inline
nsCorr::CompJaccard::CompJaccard (const string & Mot) throw ()
 : Mot (Mot) {}

inline
nsCorr::CompJaccard::~CompJaccard (void) throw () {}

inline
bool nsCorr::CompJaccard::operator () (const string & A, const string & B)
                                                             const throw ()
{
    return false;
    //return Jaccard(A.c_str(), Mot.c_str()) < Jaccard(B.c_str(), Mot.c_str());

} // operator()()

inline
nsCorr::CompLevenshteinC::CompLevenshteinC (const string & Mot) throw ()
 : Mot (Mot) {}

inline
nsCorr::CompLevenshteinC::~CompLevenshteinC (void) throw () {}

inline
bool nsCorr::CompLevenshteinC::operator () (const string & A, const string & B)
                                                             const throw ()
{
    return abs(LevenshteinC(A, Mot) - LevenshteinC(B, Mot)) <
                                            numeric_limits<float>::epsilon();

} // operator()()

#undef LINKSTR
