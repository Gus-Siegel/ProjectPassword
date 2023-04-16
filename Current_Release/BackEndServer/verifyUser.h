#ifndef VERIFY_USER_H
#define VERIFY_USER_H

#include "compare_strings.h"
#include "pythonListToCharState.h"
#include "verifyUserConstants.h"
#include <string>


// verifying functions
bool verifyUser( CharStateList &one, CharStateList &other );
bool verifyUser( const std::string strOne, const std::string strTwo );
#endif // VERIFY_USER_H