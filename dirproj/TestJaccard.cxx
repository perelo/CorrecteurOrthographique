/*
 * @File TestJaccard.cxx
 *
 * @Date 02-11-2012
 *
 */

#include <iostream>
#include <string>

#include "Jaccard.h"

using namespace std;
using namespace nsUtil;

namespace
{
    template <typename T>
    void AffichBin (T x)
    {
        for (unsigned i(sizeof(x)); i--; )
        {
            for (unsigned j(8); j--; )
                cout << (1 & (x >> (i*8 + j)));
            cout << ' ';
        }

    } // AffichBin

} // anonymous namespace

int main ()
{
    string A ("accueil");
    string B ("acceuil");

    cout << A << "\n\t";
    for (unsigned i(0); i < A.size(); ++i)
        AffichBin(A[i]);

    cout << '\n' << B << "\n\t";
    for (unsigned i(0); i < B.size(); ++i)
        AffichBin(B[i]);
    cout << endl;

    cout << "J(\"" << A << "\", \"" << B << "\") = "
         << Jaccard(A.c_str(), B.c_str()) << endl;

    return 0;

} // main()
