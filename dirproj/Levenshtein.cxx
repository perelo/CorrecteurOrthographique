/*
 * @File Levenshtein.cxx
 *
 */
#include <string>
#include <algorithm>    // min

#include "Levenshtein.h"

using namespace std;

unsigned nsUtil::Levenshtein(const string & MotOrig, const string & MotDest)
{
    const string::size_type LgOrig = MotOrig.size();
    const string::size_type LgDest = MotDest.size();

    if (0 == LgOrig) return LgDest;     // que des insertions
    if (0 == LgDest) return LgOrig;     // que des suppressions

    // initialisation de la matrice D
    unsigned D[LgOrig+1][LgDest+1];
    for (unsigned i(0); i <= LgOrig; ++i) D[i][0] = i;
    for (unsigned i(1); i <= LgDest; ++i) D[0][i] = i;
    for (unsigned i(1); i <= LgOrig; ++i)
        for (unsigned j(1); j <= LgDest; ++j)
            D[i][j] = 0;

    // remplissage de D
    for (unsigned i(1); i <= LgOrig; ++i)
        for (unsigned j(1); j <= LgDest; ++j)
            D[i][j] = min(min(
                          D[i-1][j  ] + 1,
                          D[i  ][j-1] + 1),
                          D[i-1][j-1] + (MotOrig[i-1] == MotDest[j-1] ? 0
                                                                      : 1));

    return D[LgOrig][LgDest];

} // Levenshtein()
