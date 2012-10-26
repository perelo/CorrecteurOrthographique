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

    void TestLevenshtein()
    {
        clock_t Deb;
        double  Temps;
        string MotOrig, MotDest, NomDico = "../materiel4/dico2012.txt";
        VString Dico;

        MotOrig = "acceuil";
        MotDest = "accueil";
        cout << "Levenshtein(" << MotOrig << ", " << MotDest << ") = "
             << Levenshtein(MotOrig, MotDest) << endl;

        MotOrig = "arborigène";
        MotDest = "aborigène";
        cout << "Levenshtein(" << MotOrig << ", " << MotDest << ") = "
             << Levenshtein(MotOrig, MotDest) << endl;

        MotOrig = "baillonette";
        MotDest = "baïonnette";
        cout << "Levenshtein(" << MotOrig << ", " << MotDest << ") = "
             << Levenshtein(MotOrig, MotDest) << endl;

        MotOrig = "banquaire";
        MotDest = "bancaire";
        cout << "Levenshtein(" << MotOrig << ", " << MotDest << ") = "
             << Levenshtein(MotOrig, MotDest) << endl;

        MotOrig = "déconnection";
        MotDest = "déconnexion";
        cout << "Levenshtein(" << MotOrig << ", " << MotDest << ") = "
             << Levenshtein(MotOrig, MotDest) << endl;

        ifstream is ("../materiel4/dico2012.txt");
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
            Levenshtein(MotOrig, *i);
        Temps = (clock() - Deb) / (double) CLOCKS_PER_SEC;

        cout << "Temps de Levenshtein(" << MotOrig << ", mot du dico) = "
             << Temps * 1000 << " ms" << endl;

    } // TestLevenshtein()

} // namespace anonyme

int main (void)
{
    TestLevenshtein();

    return 0;

} // main()
