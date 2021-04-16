/*
Jacobo Soffer Levy
A01028653
Declaration of the Records class.
This class loads and stores the logs,
also handles other initialization
steps and searching.
Modified: 19/03/21
*/
#ifndef RECORDS_H
#define RECORDS_H

#include <iostream>
#include <fstream>
#include "linked_list.h"
#include "record.h"

class Records {
public:
  // Constructor. Loads and sorts the logs.
  // Params: file name where the records are stored (string)
  Records(std::string);
  // This method finds and prints records
  // between a pair of dates.
  // Params:
  // - from (DateTime): Date where the search begins.
  // - to (DateTime): Date where the search ends.
  // Both dates are inclusive. e € [from, to]
  void find(DateTime from, DateTime to);
private:
  // Binary search algorithm.
  // Params:
  // date (DateTime): The date of the record that wants to be retrieved.
  // Return value: Index of the record, if not found -1.
  int search(DateTime);
  // Stores the records.
  LinkedList<Record> records;
};

#endif