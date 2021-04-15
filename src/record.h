/*
Jacobo Soffer Levy
A01028653
Record class declaration.
Represents a log entry.
Modified: 19/03/21
*/
#ifndef PI_RECORD_H
#define PI_RECORD_H

#include <iostream>
#include "date_time.h"

class Record {
  public:
    // Constructor, takes the
    // log entry as a parameter
    Record(std::string);
    DateTime getDate();
    std::string getIp();
    std::string getPort();
    std::string getReason();
    // Returns the original entry.
    std::string getEntry();

    // For convenience, these operators
    // compare the dates of the records.
    bool operator>(Record&);
    bool operator<(Record&);
    // Outputs the full entry.
    friend std::ostream& operator<<(std::ostream&, Record&);
  private:
    std::string ip;
    std::string port;
    std::string reason;
    std::string entry;  // The full entry
    DateTime date;
};

#endif