#include <iostream>
#include <fstream>
#include <string>

#include "CHashMap.h"

using namespace std;
using namespace nsSdD;

namespace
{
    void RemplirMapAvecDico (const string & PathDico, CHashMap * const Dico)
    {
        ifstream is (PathDico.c_str());
        if (! is)
        {
            is.close();
            return;
        }

        for (string Str; getline(is, Str); )
            Dico->Put(Str);

        is.close();

    } // RemplirMapAvecDico()

} // namespace anonyme

int main (void)
{
    CHashMap Dico (424581);
    RemplirMapAvecDico("../materiel4/dico2012.txt", &Dico);

    cout << Dico.Get("baïonnette") << endl;

    return 0;

} // main()

