#pragma once
#include "curses.h"

// Base class that generates all the borders and the view
// while providing many hooks for values
class View {

private:
	int padding = 2;
	int height;
	int width;
	int start_y = padding;
	int start_x = padding;
	int yMax;
	int xMax;
	int middleX;
	int middleY;
	WINDOW *win;

protected:
	int getPadding();
	int getHeight();
	int getWidth();
	int getStartY();
	int getStartX();
	int getYMax();
	int getXMax();
	int getMiddleX();
	int getMiddleY();
	WINDOW* getWin();
	const static int PROMPT_X = 5;
	const static int PROMPT_Y = 2;

public:
	View();
	~View();

};