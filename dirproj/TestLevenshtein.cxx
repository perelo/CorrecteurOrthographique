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
        string MotDico;
        string NomDico = "../materiel4/dico_iso.txt";
        string NomTest = "TestFiles/test_leven_iso.txt";
        VString Dico;

        /*
         * Creation du dictionnaire
         */
        ifstream DicoIs (NomDico.c_str());
        if (DicoIs.fail())
        {
            cout << "Ouverture du dico \"" << NomDico
                << "\" impossible" << endl;
            DicoIs.close();
            return;
        }
        for (; ! (getline(DicoIs, MotDico)).eof(); )
            Dico.push_back(MotDico);
        DicoIs.close();

        /*
         * Test
         */
        ifstream TestIs (NomTest.c_str());
        if (TestIs.fail())
        {
            cout << "Ouverture du fichier test impossible" << endl;
            TestIs.close();
            return;
        }
        for (string MotOrig, MotDest; ! (getline(TestIs, MotOrig)).eof(); )
        {
            if (getline(TestIs, MotDest).eof())
            {
                // leven avec tout le dico
                Deb = clock();
                for (Iter_t i (Dico.begin()); i < Dico.end(); ++i)
                    LevenshteinD(MotOrig, *i);
                Temps = (clock() - Deb) / (double) CLOCKS_PER_SEC;

                cout << "Temps de LevenshteinD(" << MotOrig << ", mot du dico) = "
                    << Temps * 1000 << " ms" << endl;

                break;
            }
            cout << "LevenshteinD(" << MotOrig << ", " << MotDest << ") = "
                 << LevenshteinD(MotOrig, MotDest) << endl;

        }
        TestIs.close();

    } // TestLevenshteinD()

} // namespace anonyme

int main (void)
{
    TestLevenshteinD();

    return 0;

} // main()
