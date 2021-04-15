/*
Jacobo Soffer Levy
A01028653
Definition for DateTime
class methods
Modified: 19/03/21
*/
#include "date_time.h"
#include "invalid_date.h"
#include <string.h>

using namespace std;

// Used to convert months from string to int
const unordered_map<string, int> DateTime::months = {
      {"Jan", 0},
      {"Feb", 1},
      {"Mar", 2},
      {"Apr", 3},
      {"May", 4},
      {"Jun", 5},
      {"Jul", 6},
      {"Aug", 7},
      {"Sep", 8},
      {"Oct", 9},
      {"Nov", 10},
      {"Dec", 11}
};

DateTime::DateTime(string from) : dateString(from) {
  // Validate the date is valid with a regex
  if (from.length() != 15 || !regex_match(from, regex("([A-Z][a-zA-Z]{2}\\s[0-3]\\d\\s[0-2]\\d:[0-5]\\d:[0-5]\\d)"))) {
    throw InvalidDate("Invalid date");
  }
  dateStruct.tm_sec = stoi(from.substr(13, 2));
  dateStruct.tm_min = stoi(from.substr(10, 2));
  dateStruct.tm_hour = stoi(from.substr(7, 2));
  dateStruct.tm_mday = stoi(from.substr(4, 2));
  string monthStr = from.substr(0, 3);
  if (months.count(monthStr) != 1) {
    throw InvalidDate("Invalid month.");
  }
  dateStruct.tm_mon = months.at(monthStr);
  dateStruct.tm_year = 121;  // We assume 2021
  date = mktime(&dateStruct);
}

int DateTime::getSeconds() {
  return dateStruct.tm_sec;
}

int DateTime::getMinutes() {
  return dateStruct.tm_min;
}

int DateTime::getHour() {
  return dateStruct.tm_hour;
}

int DateTime::getDate() {
  return dateStruct.tm_mday;
}

int DateTime::getMonth() {
  return dateStruct.tm_mon;
}

string DateTime::getDateString() {
  return dateString;
}

bool DateTime::operator==(const DateTime &other) {
  return this->date == other.date;
}

bool DateTime::operator!=(const DateTime &other) {
  return this->date != other.date;
}

bool DateTime::operator>(const DateTime &other) {
  return this->date > other.date;
}

bool DateTime::operator<(const DateTime &other) {
  return this->date < other.date;
}

ostream& operator<<(ostream& out, DateTime& d) {
  return out << d.dateString;
}