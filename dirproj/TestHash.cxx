/*
 * @File TestHash.cxx
 *
 * @Date 30-10-2012
 *
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

namespace
{
    int Cap = 1000000;
    int Hash (string Str)
    {
        int Hash (0);
        for (unsigned i(0); i < Str.size(); ++i)
            Hash = (Hash * 31 + Str[i]) % Cap;

        return Hash;

    } // Hash
}

int main ()
{
    ifstream is ("../materiel4/dico_iso.txt");
    if (!is)
    {
        cout << "fail to open ifstream" << endl;
    }

    for (string s; getline(is, s); )
    {
        if (Hash(s) < 0)
            cout << "hash de " << s << " negatif" << endl;
    }

}
