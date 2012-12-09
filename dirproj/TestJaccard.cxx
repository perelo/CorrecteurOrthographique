/*
 * @File TestJaccard.cxx
 *
 * @Date 02-11-2012
 *
 */

#include <iostream>
#include <string>

#include <ctime>

#include "Jaccard.h"
#include "Correcteur.h"
#include "CLink.h"

using namespace std;
using namespace nsUtil;
using namespace nsCorr;
using namespace nsSdD;

namespace
{
    void TestJaccard ()
    {
        string MotOrig ("$accueil$");
        string MotDest ("$acceuil$");
        CLink<string> * TrigOrig = GetTrigrammes(MotOrig);
        CLink<string> * TrigDest = GetTrigrammes(MotDest);

        cout << "Jaccard(" << MotOrig << ", " << MotDest << ") = "
             << Jaccard(TrigOrig, TrigDest) << endl;

        const unsigned Nb (1000000);
        clock_t start (clock());
        for (unsigned i(Nb); i--; ) Jaccard(TrigOrig, TrigDest);
        float tps ((clock() - start) / float(CLOCKS_PER_SEC) * 1000);

        cout << Nb << " x Jaccard() en " << tps << " ms"
             << " soit un Jaccard() en " << (tps / Nb) << " ms" << endl;

        delete TrigOrig;
        delete TrigDest;

    } // TestJaccard()

} // anonymous namespace

int main ()
{
    TestJaccard();

    return 0;

} // main()
