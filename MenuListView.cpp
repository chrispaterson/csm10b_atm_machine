#include "stdafx.h"
#include "MenuListView.h"


void MenuListView::createMenu(std::string promptUser, std::string choices[] , int choicesLen) {

	int choice = 0;

	// Prints out the prompt for the user
	mvwprintw(getWin(), PROMPT_Y , PROMPT_X, promptUser.c_str());

	keypad(getWin(), true);
	curs_set(0);

	while (true) {
		for (int i = 0; i < choicesLen; i++) {
			if (i == selected) {
				wattron(getWin(), A_REVERSE);
			} 
			mvwprintw(getWin(), PROMPT_Y + i + 2, PROMPT_X, choices[i].c_str());
			wattroff(getWin(), A_REVERSE);

		}
		choice = wgetch(getWin());

		switch (choice) {
		case KEY_UP :
		case 107 :
			selected--;
			if (selected == -1) {
				selected = 0;
			}
			break;
		case KEY_DOWN :
		case 106 :
			selected++;
			if (selected == choicesLen) {
				selected = choicesLen - 1;
			}
			break;
		case 9 :
			selected++;
			if (selected == choicesLen) {
				selected = 0;
			}
			break;
		default:
			break;
		}
		if (choice == 10) {
			curs_set(1);
			break;
		}

	}

}
int MenuListView::getSelected() {
	return selected;
}