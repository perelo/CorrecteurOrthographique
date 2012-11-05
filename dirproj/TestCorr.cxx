/*
 * @File TestCorr.cxx
 *
 * @Date 01-11-2012
 *
 */

#include <iostream>
#include <vector>
#include <string>

#include <ctime>
#include <fstream>

#include "Correcteur.h"
#include "CHashStr.h"

using namespace std;
using namespace nsCorr;

#include "MathUtil.h"
#include "CLink.h"

int main (int argc, char * argv [])
{
    nsUtil::CHashStr Hashor;
    DicoMap_t Dico (&Hashor, 1000000);
    TrigMap_t DicoTrig (&Hashor, 40000);
    cout << "Construction des dicos" << endl;
    clock_t start = clock();
    RemplirDicoAvecFichier("../materiel4/dico_iso.txt", Dico, DicoTrig);
    cout << "Fin construction : " << (clock() - start) / float(CLOCKS_PER_SEC)
         << endl;

    string Mot ("acceuil");
    cout << "\nMot a corriger : " << Mot << endl;
    vector<string> VProp;
    if (CorrigerMot(Mot, Dico, DicoTrig, VProp))
    {
        cout << "Corrections :" << endl;
        for (vector<string>::const_iterator It (VProp.begin());
                                                        It < VProp.end(); ++It)
            cout << '\t' << *It << endl;
    }
    else
        cout << "mot juste" << endl;

    return 0;

} // main()
