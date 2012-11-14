/*
 * @File TestCorr.cxx
 *
 * @Date 01-11-2012
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include <ctime>
#include <fstream>

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

    unsigned NbMotsCorrects, NbMotsCorrige, NbMotsNonCorriges;
    NbMotsCorrects = NbMotsCorrige = NbMotsNonCorriges = 0;

    ifstream is ("../materiel4/fautes_iso.txt");
    cout << "\nCorrection des mots dans le fichier" << endl;
    start = clock();
    for (string Ligne, MotOrig, MotCorrige, Delim; getline(is, Ligne); )
    {
        istringstream isstr(Ligne);
        isstr >> MotOrig >> Delim >> MotCorrige;

        vector<string> VProps;
        cout << "correction du mot " << MotOrig << endl;
        if (0 == CorrigerMot(MotOrig, Dico, DicoTrig, VProps))
        {
            ++NbMotsCorrects;
            continue;
        }

        bool isCorrige (false);
        for (vector<string>::iterator iProp (VProps.begin());
                                                iProp < VProps.end(); ++iProp)
        {
            if (*iProp == MotCorrige)
            {
                isCorrige = true;
                ++NbMotsCorrige;
                break;
            }
            else continue;
        }
        if (! isCorrige)
            ++NbMotsNonCorriges;

    }
    float temps ((clock() - start) / float(CLOCKS_PER_SEC));
    cout << "Fin correction des mots" << endl;
    is.close();

    cout << "Bilan : " << temps * 1000 << "ms\n"
         << '\t' << NbMotsCorrects << " mots corrects\n"
         << '\t' << NbMotsCorrige  << " mots dans la liste des suggestions\n"
         << '\t' << NbMotsNonCorriges << " mots non corriges\n";

    return 0;

} // main()
