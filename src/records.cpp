/*
Jacobo Soffer Levy
A01028653
Definition of the Records
class methods.
Modified: 19/03/21
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
  int comps = sort(0, records.getSize() - 1);
  auto endTime = chrono::high_resolution_clock::now();
  auto totalTime = endTime - startTime;
  cout << "Sorting comparisons: " << comps << endl;
  cout << "Sorting Time: " << totalTime / chrono::milliseconds(1) << " ms." << endl;
  cout << "Records in registry: " << records.getSize() << endl;
  ofstream orderedFile("bitacora_ordenada.txt");
  for (int i = 0; i < records.getSize(); i++) {
    orderedFile << (records[i]->getData().getEntry()) << endl;
  }
  orderedFile.close();
}

int Records::sort(int low, int high) {
  if (low >= high) return 0;
  int partRes[2] = { -1, -1 };
  partition(low, high, partRes);
  // [low...pi-1]
  int c1 = sort(low, partRes[0] - 1);
  // [pi+1...high]
  int c2 = sort(partRes[0] + 1, high);
  return partRes[1] + c1 + c2;
}

void Records::partition(int low, int high, int res[2]) {
  int comps = 0;
  Record pivot = records[high]->getData();
  int i = (low - 1);

  for (int j = low; j <= high - 1; j++) {
    comps++;
    // If current element is smaller than the pivot 
    if (records[j]->getData() < pivot) {
      i++; // increment index of smaller element
      Record tmp = records[i]->getData();
      *records[i] = records[j]->getData();
      *records[j] = tmp;
    }
  }
  Record temp = records[high]->getData();
  *records[high] = records[i + 1]->getData();
  *records[i + 1] = temp;
  res[0] = i + 1;
  res[1] = comps;
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