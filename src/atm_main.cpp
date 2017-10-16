#include <iostream>
#include "ncurses.h"
#include "ATMController.h"

using namespace std;

int main() {

  initscr();

  endwin();

  ATMController controller;
  controller.begin();

  return 0;
}
