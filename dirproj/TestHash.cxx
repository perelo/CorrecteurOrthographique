/*
 * @File TestHash.cxx
 *
 * @Date 30-10-2012
 *
 */

#include <iostream>
#include <string>

#include <ctime>

using namespace std;

namespace
{
    int Cap = 1000000;
    unsigned Hash (const string Str)
    {
        unsigned Hash (0);
        for (unsigned i(0); i < Str.size(); ++i)
            Hash = (Hash * 31 + Str[i]) % Cap;

        return Hash;

    } // Hash
}

int main ()
{
    const unsigned Nb (1000000);

    clock_t start (clock());
    for (unsigned i(0); i < 1000000; ++i) Hash("string");
    float tps ((clock() - start) / float(CLOCKS_PER_SEC) * 1000);

    cout << Nb << " x Jaccard() en " << tps << " ms"
         << " soit un Jaccard() en " << (tps / Nb) << " ms" << endl;

    return 0;

} // main()
