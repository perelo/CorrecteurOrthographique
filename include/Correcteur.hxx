/*
 * @File Correcteur.hxx
 *
 * @Date 01-11-2012
 *
 */
#ifndef __CORRECTEUR_HXX__
#define __CORRECTEUR_HXX__

#include <string>

#include "Correcteur.h"

inline
void nsCorr::AjouterDelimiteur (std::string & Mot) throw ()
{
    char Delimiteur ('$');
    Mot.insert(Mot.begin(), Delimiteur);
    Mot.push_back(Delimiteur);

} // AjouterDelimiteur


#endif /* __CORRECTEUR_HXX__ */
