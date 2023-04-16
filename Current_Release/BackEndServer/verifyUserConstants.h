#ifndef VERIFY_USER_CONSTANTS
#define VERIFY_USER_CONSTANTS

#include<string>
#include<unordered_set>

// value constants
const char BACKSPACE = 0x08;
const std::string PYTHON_BACKSPACE_STR = (std::string)"\\x08";

// weight constants
const double MISSING_CHAR_WEIGHT = 1.0;
const double MISTYPE_WEIGHT = 1.0;
const double TIME_ERROR_WEIGHT = 1.0;

// maximum error before recursion stops
const int MAX_SPELLING_ERROR = 8;

// constants
// buffer represents a position where no char is located, to keep alignment
//    between multiple CharStateLists 
const double BUFFER = -1001.0;

// acceptable error for user
const double MAX_ACCEPTABLE_USER_ERROR = 0.5;
const double MAX_ACCEPTABLE_SPELLING_ERROR = .1; // 10% spelling error allowed
const double MAX_ACCEPTABLE_TIME_ERROR = .5; // 25% average time difference


	// APPLY_BACKSPACES to remove characters before any backspace
	// setting both has the same result as only setting BEFORE_SET_DELAY
// before set delay: time taken to press backspace is added to next character
const bool APPLY_BACKSPACES_BEFORE_SET_DELAY = false;
// after set delay: time taken to press backspace is ignored in the list
const bool APPLY_BACKSPACES_AFTER_SET_DELAY = true;


const bool TIME_BASED_INPUT = true; // set to true if input contains times
// any UNRECOGNIZED_CHAR and EMPTY_STRING_CHAR is 
// 	treated the same as another
const char UNRECOGNIZED_CHAR = (char)128; // first extended ascii character
const char EMPTY_STRING_CHAR = '\0'; // null character



// string of characters that should be removed
const std::unordered_set<char> EXCLUDED_CHAR_STATE_CHARS( {
                                                           UNRECOGNIZED_CHAR, 
                                                           EMPTY_STRING_CHAR, 
                                                           '\n', 
                                                           '\t', 
                                                           '\r', 
                                                           (char)0x27
                                                          } );


#endif // VERIFY_USER_CONSTANTS