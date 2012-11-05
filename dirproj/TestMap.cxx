/*
 * @File TestMap.cxx
 *
 * @Date 26-10-2012
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>  // setw()

#include <cmath>
#include <ctime>

#include "CHashMap.h"
#include "CHashStr.h"
#include "MathUtil.h"

using namespace std;
using namespace nsSdD;
using namespace nsUtil;

namespace
{
    void RemplirMapAvecDico (const string & PathDico,
                             CHashMap<string, string> & Dico)
    {
        ifstream is (PathDico.c_str());
        if (! is)
        {
            is.close();
            return;
        }

        for (string Str; getline(is, Str); )
            Dico[Str] = Str;

        is.close();

    } // RemplirMapAvecDico()

    void TestMapPoisson (const string & Path)
    {
        clock_t start;
        double temps;
        CHashStr Hashor;
        CHashMap<string, string> Dico (&Hashor, 1000000);
//        CHashMap<string, string> Dico (&Hashor);

        start = clock();
        RemplirMapAvecDico(Path, Dico);
        temps = (clock() - start) / float(CLOCKS_PER_SEC);

        float Alpha = float(Dico.GetNbElem()) / Dico.GetCapacity();
        vector<unsigned> VNbEntree;
        Dico.FillNbEntree(VNbEntree);
        cout << "Temps de lecture et construction du dictionnaire = "
             << temps*1000 << " ms" << '\n'
             << "Dictionnaire : "
             << "alpha = " << Alpha << ", "
             << "NbMots = " << Dico.GetNbElem() << ", "
             << "MaxBoite = " << VNbEntree.size() << '\n' << endl;

        cout << setw(3) << "k" << setw(10) << "NbEntree"
             << setw(12) << "Poisson" << endl;
        for (unsigned i(0); i < VNbEntree.size(); ++i)
            cout << setw(3) << i << setw(10) << VNbEntree[i]
                 << setw(12) << fixed << setprecision(2)
                 << Dico.GetCapacity() * nsUtil::Poisson(Alpha, i)
                 << endl;

    } // TestMapPoisson()

} // namespace anonyme

int main (void)
{
    TestMapPoisson ("../materiel4/dico_iso.txt");

    return 0;

} // main()

