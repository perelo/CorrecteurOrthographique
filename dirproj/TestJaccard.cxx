/*
 * @File TestJaccard.cxx
 *
 * @Date 02-11-2012
 *
 */

#include <iostream>
#include <string>

#include "Jaccard.h"
#include "Correcteur.h"

using namespace std;
using namespace nsUtil;
using namespace nsCorr;

int main ()
{
    string MotOrig ("$accueil$");
    string MotDest ("$acceuil$");
    cout << "Jaccard(" << MotOrig << ", " << MotDest << ") = "
         << Jaccard(GetTrigrammes(MotOrig), GetTrigrammes(MotDest)) << endl;

    return 0;

} // main()
