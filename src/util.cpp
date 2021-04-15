/*
Jacobo Soffer Levy
A01028653
Definition of utility functions.
Modified: 19/03/21
*/
#include "util.h"

using namespace std;

DateTime getDate(string prompt, bool& shouldBreak) {
  string input;
  cout << prompt;
  getline(cin, input);
  trim(input);
  if (input[0] == 'q') {
    shouldBreak = true;
    return DateTime("Jan 04 18:49:57");
  }
  try {
    DateTime date(input);
    return date;
  } catch (InvalidDate e) {
    cout << "Invalid date, please try again." << endl;
    cout << "Enter the date in format Mmm dd hh:mm:ss" << endl;
    cout << "Example: Jul 01 19:49:00" << endl;
    return getDate(prompt, shouldBreak);
  }
}

inline void leftTrim(string& str) {
  str.erase(str.begin(), find_if(str.begin(), str.end(), [](unsigned char ch) {
    return !isspace(ch);
  }));
}

inline void rightTrim(string& str) {
  str.erase(find_if(str.rbegin(), str.rend(), [](unsigned char ch) {
    return !isspace(ch);
  }).base(), str.end());
}

inline void trim(string& str) {
  leftTrim(str);
  rightTrim(str);
}