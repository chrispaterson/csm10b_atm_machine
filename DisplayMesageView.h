#pragma once
#include "View.h"
#include <string>
class DisplayMesageView :
	public View
{
public:
	DisplayMesageView();
	void displayMessage(std::string message);
	~DisplayMesageView();
};

