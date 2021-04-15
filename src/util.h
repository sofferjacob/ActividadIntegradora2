/*
Jacobo Soffer Levy
A01028653
Utility functions declaration.
Modified: 19/03/21
*/
#ifndef PI_UTIL_H
#define PI_UTIL_H

#include <iostream>
#include "date_time.h"
#include "invalid_date.h"

// Asks the user to enter a date. If an invalid date
// is entered, the function is called again, this
// time displaying a helpful message.
// Parameters:
// - prompt (string): The prompt to show the user.
// - shouldBreak (bool&): If the user enters 'q'
// this flag is set, so the caller code can exit the program.
// This functionality is handled this way so the caller is aware
// the program is terminating.
// Return values: The date entered by the user (DateTime)
DateTime getDate(std::string prompt, bool& shouldBreak);

// Trims a string (in place) from the left side.
// Parameter: The string to trim.
// Return value: None.
inline void leftTrim(std::string& str);
// Trims a string (in place) from the right side.
// Parameter: The string to trim.
// Return value: None.
inline void rightTrim(std::string& str);
// Trims a string (in place) from both sides.
// Parameter: The string to trim.
// Return value: None.
inline void trim(std::string& str);

#endif