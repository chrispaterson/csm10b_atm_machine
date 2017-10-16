#include "ATMController.h"
void ATMController:: clearConsole() {
  for(int i = 0; i < 100; i++) {
    cout << endl;
  }
};
void ATMController:: begin() {
  clearConsole();
};
