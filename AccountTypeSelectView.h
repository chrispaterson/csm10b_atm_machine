#pragma once
#include "MenuListView.h"
#include <string>

// view to show the different types of 
// accounts one may create
class AccountTypeSelectView :
	public MenuListView
{
private:

	// Number of different account types
	const static int NUM_ACCOUNT_TYPES = 4;

	// prompt the user above the menu
	std::string prompt = "Please select account type";

	// items array
	std::string accountTypes[NUM_ACCOUNT_TYPES] = { "Checking", "Savings", "CD", "Cancel" };

public:
	AccountTypeSelectView();
};

