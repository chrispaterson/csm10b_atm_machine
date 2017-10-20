#include <iostream>
#include "curses.h"
#include "ATMController.h"

using namespace std;

int main() {

  int padding = 2;
  int height;
  int width;
  int start_y = padding;
  int start_x = padding;
  int yMax;
  int xMax;

  initscr();
  cbreak();

  getmaxyx(stdscr, yMax, xMax);

  height = yMax - 2 * padding;
  width = xMax - 2 * padding;

  //WINDOW * win = newwin(height, width, start_y, start_x);
  WINDOW * win = newwin(height, width, start_y, start_x);

  refresh();

  box(win, 0, 0);
  int middleY = height / 2;
  int middleX = width / 2;
  mvwprintw(win, middleY , middleX - 28 , "Please Enter Account Number");
  move(height / 2 + 1 + padding ,width / 2 - 28 + padding);
  wrefresh(win);

  keypad(win, true);

  string choices[3] = { "Option 1", "Option 2", "Option 3" };
  int choice;
  int highlight = 0;


  while(true) {
    for(int i = 0; i < 3; i ++) {
      if(i == highlight) {
        wattron(win, A_REVERSE);
      }
      mvwprintw(win, middleY + i + 1, middleX - 28, choices[i].c_str());
      wattroff(win, A_REVERSE);
    }
    choice = wgetch(win);

    switch(choice) {
      case KEY_UP:
        if(highlight > 0) {
          highlight--;
        }
        break;
      case KEY_DOWN:
        if(highlight < 2) {
          highlight++;
        }
        break;
      default:
        break;
    }
    if(choice == 10) {
      break;
    }
  }

  getch();
  endwin();

  /*
  ATMController controller;
  controller.begin();
  */

  return 0;
}
