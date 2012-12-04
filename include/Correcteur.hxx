/*
 * @File Correcteur.hxx
 *
 * @Date 01-11-2012
 *
 */
#ifndef __CORRECTEUR_HXX__
#define __CORRECTEUR_HXX__

#include <string>
#include <limits>   // float::epsilon()

#include "Correcteur.h"
#include "Levenshtein.h"
#include "Jaccard.h"

inline
void nsCorr::AjouterDelimiteur (std::string & Mot) throw ()
{
    char Delimiteur ('$');
    Mot.insert(Mot.begin(), Delimiteur);
    Mot.push_back(Delimiteur);

} // AjouterDelimiteur

inline
nsCorr::CompLevenshteinC::CompLevenshteinC (const std::string & Mot) throw ()
 : Mot (Mot) {}

inline
nsCorr::CompLevenshteinC::~CompLevenshteinC (void) throw () {}

inline
bool nsCorr::CompLevenshteinC::operator () (const std::string & A,
                                            const std::string & B)
                                                                 const throw ()
{
    return nsUtil::LevenshteinC(A, Mot) - nsUtil::LevenshteinC(B, Mot) >
           std::numeric_limits<float>::epsilon();

} // operator()()

#endif /* __CORRECTEUR_HXX__ */
