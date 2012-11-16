/*
 * @File TestCorr.cxx
 *
 * @Date 01-11-2012
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include <ctime>

#include "Correcteur.h"
#include "CHashStr.h"
#include "CLink.h"

using namespace std;
using namespace nsCorr;
using namespace nsSdD;

int main (int argc, char * argv [])
{
    nsUtil::CHashStr Hashor;
    DicoMap_t Dico (&Hashor, 1000000);
    TrigMap_t DicoTrig (&Hashor, 40000);    // il y a au plus ~20000 trigrammes
    cout << "Construction des dicos" << endl;
    clock_t start = clock();
    RemplirDicoAvecFichier("../materiel4/dico_iso.txt", Dico, DicoTrig);
    cout << "Fin construction : " << (clock() - start) / float(CLOCKS_PER_SEC)
         << endl;

    unsigned NbMotsDansProps, NbMotsCorrige, NbMotsNonCorriges;
    NbMotsDansProps = NbMotsCorrige = NbMotsNonCorriges = 0;

    ifstream is ("../materiel4/fautes_iso.txt");
    cout << "\nCorrection des mots dans le fichier" << endl;
    start = clock();
    for (string Ligne, Delim (">"); getline(is, Ligne); )
    {
        size_t PosDelim (Ligne.find_first_of(Delim));
        string MotOrig    (Ligne.begin(), Ligne.begin()+PosDelim-1);
        string MotCorrige (Ligne.begin() + PosDelim+2, Ligne.end());

        vector<string> VProps;
        cout << "correction du mot " << MotOrig << endl;
        if (0 == CorrigerMot(MotOrig, Dico, DicoTrig, VProps) ||
            *VProps.begin() == MotCorrige)
        {
            ++NbMotsCorrige;
            continue;
        }

        vector<string>::iterator iProp (VProps.begin());
        for (; iProp < VProps.end(); ++iProp)
        {
            if (*iProp == MotCorrige)
            {
                ++NbMotsDansProps;
                break;
            }
        }
        if (iProp == VProps.end())
            ++NbMotsNonCorriges;

    }
    is.close();
    float temps ((clock() - start) / float(CLOCKS_PER_SEC));
    cout << "Fin correction des mots" << endl;

    cout << "Bilan : " << temps * 1000 << "ms\n"
         << '\t' << NbMotsCorrige     << " bonnes corrections\n"
         << '\t' << NbMotsDansProps   << " dans la liste des propositions\n"
         << '\t' << NbMotsNonCorriges << " non corriges" << endl;

    return 0;

} // main()
