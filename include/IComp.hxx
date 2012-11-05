/*
 * @File IComp.hxx
 *
 * @Date 03-11-2012
 *
 */
#ifndef __ICOMP_HXX__
#define __ICOMP_HXX__

#include "IComp.h"

#define TEMPL    template <class T>
#define TEMPLINL TEMPL inline

#define COMP nsUtil::IComp<T>

TEMPLINL
COMP::~IComp () throw () {}

#undef ICOMP
#undef TEMPLINL
#undef TEMPL

#endif /* __ICOMP_HXX__ */
