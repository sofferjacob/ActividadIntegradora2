/*
Jacobo Soffer Levy
A01028653
Exception thrown when an
entered date is invalid or
is not on the registry.
Modified: 19/03/21
*/
#ifndef INVALID_DATE_H
#define INVALID_DATE_H

#include <stdexcept>

class InvalidDate : public std::runtime_error {
  public:
    InvalidDate(const char*);
};

#endif