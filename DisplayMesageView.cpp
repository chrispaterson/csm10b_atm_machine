#include "stdafx.h"
#include "DisplayMesageView.h"
#include <string>

// displays message in the center of the screen
void DisplayMesageView::displayMessage(std::string message) {

	// print the message at the prompt position
	mvwprintw(getWin(), PROMPT_Y, PROMPT_X, message.c_str());
	
	// now move the cursor down 
	move(PROMPT_Y + getPadding() + 1, PROMPT_X + getPadding());

	//update the window
	wrefresh(getWin());

	// wait and capture a key press (but don't use it)
	getch();
};