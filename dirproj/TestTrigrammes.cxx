/*
 * @File
 *
 * @Date 02-12-2012
 *
 */

#include <iostream>
#include <string>

#include <ctime>

#include "Correcteur.h"
#include "CLink.h"

using namespace std;
using namespace nsSdD;
using namespace nsCorr;

namespace
{
    void TestTrigrammes ()
    {
        string Mot ("accueil");

        const unsigned Nb (1000000);
        clock_t start (clock());
        for (unsigned i(Nb); i--; ) delete GetTrigrammes(Mot);
        float tps ((clock() - start) / float(CLOCKS_PER_SEC) * 1000);

        cout << Nb << " x GetTrigrammes(\"" << Mot << "\") en " << tps << " ms"
             << " soit un GetTrigrammes() en " << (tps / Nb) << " ms" << endl;

    } // TestTrigrammes()

} // anonymous namespace

int main ()
{
    TestTrigrammes();

    return 0;

} // main()
