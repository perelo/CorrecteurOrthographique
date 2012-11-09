/*
 * @File TestJaccard.cxx
 *
 * @Date 02-11-2012
 *
 */

#include <iostream>

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
    int A (13), B (7);

    cout << A << "\n\t";
    AffichBin(A);
    cout << '\n' << B << "\n\t";
    AffichBin(B);
    cout << endl;

    cout << "J(" << A << ", " << B << ") = "
         << Jaccard(A, B) << endl;

    return 0;

} // main()
