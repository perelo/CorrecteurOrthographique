/*
 * @File Levenshtein.h
 *
 * @Date 25-10-2012
 *
 */
#ifndef __LEVENSHTEIN_H__
#define __LEVENSHTEIN_H__

#include <string>

namespace nsUtil
{

    unsigned LevenshteinD(const std::string & MotOrig,
                          const std::string & MotDest) throw ();

    float    LevenshteinC (const std::string & MotOrig,
                           const std::string & MotDest) throw ();

} // namespace nsUtil

#endif /* __LEVENSHTEIN_H__ */
