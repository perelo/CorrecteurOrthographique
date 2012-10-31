/*
 * IHash.hxx
 *
 */
#ifndef __IHASH_HXX__
#define __IHASH_HXX__

#include "IHash.h"

#define TEMPL    template <class T>
#define TEMPLINL TEMPL inline

#define H nsUtil::IHash<T>

TEMPLINL
H::~IHash () throw () {}

#undef H
#undef TEMPLINL
#undef TEMPL

#endif /* __IHASH_HXX__ */
