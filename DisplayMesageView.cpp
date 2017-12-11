#include "stdafx.h"
#include "DisplayMesageView.h"
#include <string>


DisplayMesageView::DisplayMesageView()
{
}

void DisplayMesageView::displayMessage(std::string message) {
	int xPosition = PROMPT_X;
	mvwprintw(getWin(), PROMPT_Y, xPosition, message.c_str());
	move(PROMPT_Y + getPadding() + 1, xPosition + getPadding());
	wrefresh(getWin());

	getch();
};

DisplayMesageView::~DisplayMesageView()
{
}
