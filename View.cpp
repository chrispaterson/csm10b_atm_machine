#include "stdafx.h"
#include "View.h"
#include "curses.h"
#include <string>

using namespace std;

// constructor gathers values and sets variables
View::View() {
	getmaxyx(stdscr, yMax, xMax);
	height = yMax - 2 * padding;
	width = xMax - 2 * padding;

	// create our window
	win = newwin(height, width, start_y, start_x);

	refresh();

	box(win, 0, 0);
	middleY = height / 2;
	middleX = width / 2;
};

// clear all the stuff out!  No memory leaks!!
View::~View() {

	endwin();
	wclear(win);
	delwin(win);
};

// Getters/Setters
int View::getPadding() {
	return padding;
};
int View::getHeight() {
	return height;
};
int View::getWidth() {
	return width;
};
int View::getStartY() {
	return start_y;
};
int View::getStartX() {
	return start_x;
};
int View::getYMax() {
	return yMax;
};
int View::getXMax() {
	return xMax;
};
int View::getMiddleX() {
	return middleX;
};
int View::getMiddleY() {
	return middleY;
};
WINDOW * View::getWin()
{
	return win;
};