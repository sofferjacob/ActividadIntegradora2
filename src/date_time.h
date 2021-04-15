/*
Jacobo Soffer Levy
A01028653
Abstracts dates with a
proper type.
Modified: 19/03/21
*/
#ifndef DATE_TIME_H
#define DATE_TIME_H

#include <time.h>
#include <iostream>
#include <unordered_map>
#include <regex>

class DateTime {
  public:
    // Constructor.
    // Parameter: Date in format
    // Mmm dd hh:mm:ss
    DateTime(std::string);
    int getSeconds();
    int getMinutes();
    int getHour();
    // Returns the month (0 Jan...11 Dec)
    int getMonth();
    // Returns the day of the month
    int getDate();
    // Returns string representation of the date
    std::string getDateString();

    bool operator ==(const DateTime&);
    bool operator !=(const DateTime&);
    bool operator >(const DateTime&);
    bool operator <(const DateTime&);
    friend std::ostream& operator <<(std::ostream&, DateTime&);
  private:
    std::string dateString;  // Date in a human-readable form
    struct tm dateStruct;
    time_t date;
    static const std::unordered_map<std::string, int> months;
};

#endif