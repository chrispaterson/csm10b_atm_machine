#pragma once
#include "MenuListView.h"
#include "NumberFormatter.h"
#include "Account.h"

class AccountDetailView :
	public MenuListView
{
private:

	// Menu item choices
	static const int NUM_CHOICES = 6;

	// Chioces array
	std::string actions[NUM_CHOICES] = { "Deposit", "Withdrawal", "Balance", "Transfer", "Transaction History", "<- Go Back"};

	// main method
	void show(Account* account);

	
public:

	// Constructor
	AccountDetailView(Account * account);
};

