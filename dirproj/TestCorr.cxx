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
#include <utility>  // pair
#include <iomanip>  // setw()

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
    DicoMap_t Dico       (&Hashor, 1000000);
    TrigMap_t DicoTrigs  (&Hashor, 20000);  // assez mm si 44^3 trigs possibles
    cout << "Indexation des mots du dictionnaire... " << flush;
    clock_t start = clock();
    RemplirDicosAvecFichier("../materiel4/dico_iso.txt", Dico, DicoTrigs);
    cout << (clock() - start) / float(CLOCKS_PER_SEC)
         << endl;

    unsigned NbMotsDansProps, NbMotsCorrige;
    NbMotsDansProps = NbMotsCorrige = 0;
    vector<pair<string, string> > VMotsNonCorrige;

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
        CorrigerMot(MotOrig, Dico, DicoTrigs, VProps);
        if (VProps.empty())
        {
            VMotsNonCorrige.push_back(make_pair(MotOrig, MotCorrige));
            continue;
        }
        else if (VProps[0] == MotCorrige)
        {
            ++NbMotsCorrige;
            ++NbMotsDansProps;
            continue;
        }
        else
        {
            vector<string>::iterator iProp (VProps.begin()+1);
            for (; iProp < VProps.end(); ++iProp)
            {
                if (*iProp == MotCorrige)
                {
                    ++NbMotsDansProps;
                    break;
                }
            }
            if (iProp == VProps.end())
                VMotsNonCorrige.push_back(make_pair(MotOrig, MotCorrige));
        }

    }
    is.close();

    float temps ((clock() - start) / float(CLOCKS_PER_SEC));
    cout << "Fin correction des mots" << endl;

    cout << "Bilan : " << temps * 1000 << "ms\n"
         << VMotsNonCorrige.size() + NbMotsDansProps << " mots lus :\n"
         << '\t' << NbMotsCorrige          << " bonnes corrections\n"
         << '\t' << NbMotsDansProps        << " dans la liste des suggestions\n"
         << '\t' << VMotsNonCorrige.size() << " non corriges :" << endl;
    for (vector<pair<string, string> >::iterator i (VMotsNonCorrige.begin());
                                                i < VMotsNonCorrige.end(); ++i)
        cout << setw(15) << i->first << setw(25) << i->second << endl;

    cout << "Nettoyage..." << endl;
    for (TrigMap_t::iterator i (DicoTrigs.begin());
         i != DicoTrigs.end();
         ++i) delete i->second;
    cout << "OK !" << endl;

    return 0;

} // main()
