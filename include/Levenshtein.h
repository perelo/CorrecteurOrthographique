/*
 * @File Levenshtein.h
 *
 */
#ifndef __LEVENSHTEIN_H__
#define __LEVENSHTEIN_H__

#include <string>

namespace nsUtil
{

    unsigned Levenshtein(const std::string & MotOrig,
                         const std::string & MotDest);

} // namespace nsUtil

#endif /* __LEVENSHTEIN_H__ */
