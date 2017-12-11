#pragma once
#include "View.h"
#include <string>

class MenuListView :
	public View
{
private:
	int selected = 0;
public:
	int getSelected();
protected:
	void createMenu(std::string promptUser, std::string choices[] , int choicesLen);
};

