#pragma once
#include "MenuListView.h"
#include "Account.h"
class AccountDetailView :
	public MenuListView
{
private:
	static const int NUM_CHOICES = 5;
	std::string actions[NUM_CHOICES] = { "Deposit", "Withdrawal", "Balance", "Transfer", "<- Go Back"};
	void show(Account* account);
	
public:
	AccountDetailView(Account * account);
	~AccountDetailView();
};

