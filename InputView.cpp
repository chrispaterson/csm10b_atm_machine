#include "stdafx.h"
#include "InputView.h"
#include <string>

void InputView::generateSingleInput(std::string promptUser, char* input, int inputSize) {

	// Prints out the prompt for the user
	mvwprintw(getWin(), PROMPT_Y, PROMPT_X, promptUser.c_str());

	// Creates line input of specified size
	mvwgetnstr(getWin(), PROMPT_Y + 1, PROMPT_X, input, inputSize);

	wrefresh(getWin());
};
