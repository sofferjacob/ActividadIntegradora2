/*
Jacobo Soffer Levy
A01028653
main.cpp
Program's entrypoint.
Sets up the program (creates the registry)
and displays the menu, handles user interaction.
Last modified: 19/03/21
*/
#include <iostream>
#include "records.h"
#include "invalid_date.h"
#include "util.h"

using namespace std;

int main() {
  cout << "Act. Integradora 1" << endl;
  cout << "Loading records from 'bitacora.txt'..." << endl;
  try {
    Records registry("bitacora.txt");
    cout << "Logs loaded to registry." << endl;
    cout << "Ordered logs written to: ./bitacora_ordenada.txt" << endl;
    cout << "Enter 'q' at any prompt to exit the program." << endl;
    while (true) {
      bool shouldBreak = false;
      cout << "New search" << endl;
      DateTime from = getDate("Please enter start date: ", shouldBreak);
      if (shouldBreak) break;
      DateTime to = getDate("Please enter end date: ", shouldBreak);
      if (shouldBreak) break;
      cout << "=== SEARCH RESULTS ===" << endl;
      cout << "From: " << from.getDateString() << endl;
      cout << "To: " << to.getDateString() << endl;
      try {
        registry.find(from, to);
      } catch (InvalidDate e) {
        cout << "An error occured: " << e.what() << endl;
      }
      cout << "======================" << endl;
    }
  } catch(invalid_argument e) {
    cout << "File 'bitacora.txt' not found. Terminating program" << endl;
  } catch(...) {
    cout << "Sorry, an unknown error occured. Terminating program" << endl;
  }
}