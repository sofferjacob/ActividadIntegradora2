/*
Jacobo Soffer Levy
A01028653
Definition of the Records
class methods.
Modified: 13/04/21
*/
#include "records.h"
#include "invalid_date.h"
#include <chrono>

using namespace std;

Records::Records(string filename) {
  ifstream file(filename);
  if (!file.good()) {
    file.close();
    throw invalid_argument("File not found");
    return;
  }
  string currentLine;
  while (getline(file, currentLine)) {
    records.pushBack(Record(currentLine));
  }
  file.close();
  auto startTime = chrono::high_resolution_clock::now();
  records.sort();
  auto endTime = chrono::high_resolution_clock::now();
  auto totalTime = endTime - startTime;
  cout << "Sorting Time: " << totalTime / chrono::milliseconds(1) << " ms." << endl;
  cout << "Records in registry: " << records.getSize() << endl;
  ofstream orderedFile("bitacora_ordenada.txt");
  for (int i = 0; i < records.getSize(); i++) {
    orderedFile << (records[i]->getData().getEntry()) << endl;
  }
  orderedFile.close();
}

int Records::search(DateTime target) {
  int n = records.getSize();
  int left = 0;
  int right = n - 1;
  while (left <= right) {
    int m = (left + right) / 2;
    DateTime val = records[m]->getData().getDate();
    if (val == target) {
      return m;
    }
    else if (target < val) {
      right = m - 1;
    }
    else {
      left = m + 1;
    }
  }
  return -1;
}

void Records::find(DateTime from, DateTime to) {
  int l = search(from);
  if (l == -1) {
    throw InvalidDate("Start date not found on registry");
  }
  int r = search(to);
  if (r == -1) {
    throw InvalidDate("End date not found on registry");
  }
  for (; l <= r; l++) {
    cout << (records[l]->getData().getEntry()) << endl;
  }
}