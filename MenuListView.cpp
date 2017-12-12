#include "stdafx.h"
#include "MenuListView.h"


void MenuListView::createMenu(std::string promptUser, std::string choices[] , int choicesLen) {

	// int for capturing the keyboard input
	int choice = 0;

	// Prints out the prompt for the user
	mvwprintw(getWin(), PROMPT_Y , PROMPT_X, promptUser.c_str());

	// use the keyboard
	keypad(getWin(), true);

	// hide the cursor
	curs_set(0);

	// use a while loop to update the position
	while (true) {

		// draw the menu items
		for (int i = 0; i < choicesLen; i++) {
			if (i == selected) {

				// turns on the background highlight
				wattron(getWin(), A_REVERSE);
			} 

			// write out the choice
			mvwprintw(getWin(), PROMPT_Y + i + 2, PROMPT_X, choices[i].c_str());

			// turn off background highlight
			wattroff(getWin(), A_REVERSE);
		}

		// get the character they inputted
		choice = wgetch(getWin());

		// what key did they hit?
		switch (choice) {

		case KEY_UP : // arrow up
		case LOWERCASE_KKEY : // VIM style 'k'

			// decrement the selected number
			selected--;

			// if we're off the end just be the end
			if (selected == -1) {
				selected = 0;
			}
			break;

		case KEY_DOWN : // arrow down
		case LOWERCASE_JKEY : // VIM style 'j'

			// increment the selected item
			selected++;

			// if we're off the end just be the end
			if (selected == choicesLen) {
				selected = choicesLen - 1;
			}
			break;

		case TAB_KEY : // in case you want to tab through

			// increment the selected item
			selected++;

			// if we're off the end just be the end
			if (selected > choicesLen) {
				selected = 0;
			}
			break;
		}

		// if it's ENTER break out of the loop and 
		// return the cursor as well
		if (choice == 10) {
			curs_set(1);
			break;
		}

	}

}