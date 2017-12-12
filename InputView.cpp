#include "stdafx.h"
#include "InputView.h"
#include <string>

// generates a prompt and gives the user to input a line
// of text boudned by the input size
void InputView::generateSingleInput(std::string promptUser, char* input, int inputSize) {

	// Prints out the prompt for the user
	mvwprintw(getWin(), PROMPT_Y, PROMPT_X, promptUser.c_str());

	// Creates line input of specified size
	mvwgetnstr(getWin(), PROMPT_Y + 1, PROMPT_X, input, inputSize);

	// refresh the window
	wrefresh(getWin());
};
