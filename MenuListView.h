#pragma once
#include "View.h"
#include <string>

// class that creates a list of menu items to select with a prompt
// it extends the base view class
class MenuListView :
	public View
{

private:

	// the selected item in the list you pass
	int selected = 0;
	static const int LOWERCASE_JKEY = 106;
	static const int LOWERCASE_KKEY = 107;
	static const int TAB_KEY = 9;

public:

	// inline function to return value
	int getSelected() const {
		return selected;
	}

protected:

	// if this class is subclassed, here is the method for
	// creating your menu
	void createMenu(std::string promptUser, std::string choices[] , int choicesLen);

};

