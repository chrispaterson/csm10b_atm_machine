#pragma once
#include "View.h"
#include "LoginStruct.h"
#include "Account.h"

class AccountOverviewView :
	public View
{
private:
	LoginStruct * loginStructPtr;
	int selected = 0;
	void show();

	Account* getAccountFromFile(int account_id);
	Account* selectedAccount;

public:
	AccountOverviewView(LoginStruct * loginStruct);
	~AccountOverviewView();
	bool createNewSelected = false;
	int getSelected() const {
		return selected;
	}
	Account* getSelectedAccount() const {
		return selectedAccount;
	}
};

