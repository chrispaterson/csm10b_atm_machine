#pragma once
#include "MenuListView.h"
#include <string>

class AccountTypeSelectView :
	public MenuListView
{
private:
	
	const static int NUM_ACCOUNT_TYPES = 3;
	std::string prompt = "Please select account type";
	std::string accountTypes[NUM_ACCOUNT_TYPES] = { "Checking", "Savings", "CD" };

public:
	AccountTypeSelectView();
	~AccountTypeSelectView();
};

