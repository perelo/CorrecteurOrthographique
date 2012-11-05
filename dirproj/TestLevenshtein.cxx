/*
 * @File TestLevenshtein.cxx
 *
 * @Date 25-10-2012
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>      // ifstream
#include <ctime>        // clock()

#include "Levenshtein.h"

using namespace std;
using namespace nsUtil;

namespace
{
    typedef vector<string> VString;
    typedef VString::iterator Iter_t;

    void TestLevenshteinD()
    {
        clock_t Deb;
        double  Temps;
        string MotOrig, MotDest, NomDico = "../materiel4/dico_iso.txt";
        VString Dico;

        MotOrig = "acceuil";
        MotDest = "accueil";
        cout << "LevenshteinD(" << MotOrig << ", " << MotDest << ") = "
             << LevenshteinD(MotOrig, MotDest) << endl;

        MotOrig = "arborigène";
        MotDest = "aborigène";
        cout << "LevenshteinD(" << MotOrig << ", " << MotDest << ") = "
             << LevenshteinD(MotOrig, MotDest) << endl;

        MotOrig = "baillonette";
        MotDest = "baïonnette";
        cout << "LevenshteinD(" << MotOrig << ", " << MotDest << ") = "
             << LevenshteinD(MotOrig, MotDest) << endl;

        MotOrig = "banquaire";
        MotDest = "bancaire";
        cout << "LevenshteinD(" << MotOrig << ", " << MotDest << ") = "
             << LevenshteinD(MotOrig, MotDest) << endl;

        MotOrig = "déconnection";
        MotDest = "déconnexion";
        cout << "LevenshteinD(" << MotOrig << ", " << MotDest << ") = "
             << LevenshteinD(MotOrig, MotDest) << endl;

        ifstream is (NomDico.c_str());
        if (is.fail())
        {
            cout << "Ouverture du dico \"" << NomDico
                 << "\" impossible" << endl;
            is.close();
            return;
        }

        for (; ! (getline(is, MotDest)).eof(); )
            Dico.push_back(MotDest);
        is.close();

        Deb = clock();
        for (Iter_t i (Dico.begin()); i < Dico.end(); ++i)
            LevenshteinD(MotOrig, *i);
        Temps = (clock() - Deb) / (double) CLOCKS_PER_SEC;

        cout << "Temps de LevenshteinD(" << MotOrig << ", mot du dico) = "
             << Temps * 1000 << " ms" << endl;

    } // TestLevenshteinD()

} // namespace anonyme

int main (void)
{
    TestLevenshteinD();

    return 0;

} // main()
