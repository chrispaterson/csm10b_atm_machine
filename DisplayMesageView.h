#pragma once
#include "View.h"
#include <string>
class DisplayMesageView :
	public View
{

public:

	// display the message in the view
	void displayMessage(std::string message);
};

