/*
 * @File TestHash.cxx
 *
 * @Date 30-10-2012
 *
 */

#include <iostream>
#include <string>

#include <ctime>

#include "CHashStr.h"

using namespace std;

int main ()
{
    const unsigned Cap (1000000);
    const unsigned Nb  (1000000);

    const nsUtil::CHashStr Hashor;
    clock_t start (clock());
    for (unsigned i(0); i < 1000000; ++i) Hashor("string", Cap);
    float tps ((clock() - start) / float(CLOCKS_PER_SEC) * 1000);

    cout << Nb << " x Hash() en " << tps << " ms"
         << " soit un Hash() en " << (tps / Nb) << " ms" << endl;

    return 0;

} // main()
