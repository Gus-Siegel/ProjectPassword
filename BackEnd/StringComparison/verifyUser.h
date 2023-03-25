#include "compare_strings.h"
#include "pythonListToCharState.h"
#include <string>

const double MAX_ACCEPTABLE_USER_ERROR = 0.5;


// verifying functions
bool verifyUser( CharStateList &one, CharStateList &other );
bool verifyUser( const std::string strOne, const std::string strTwo );