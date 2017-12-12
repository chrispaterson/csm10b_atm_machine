#pragma once
#include "View.h"
#include "LoginStruct.h"
#include "Account.h"
#include <string>

class AccountOverviewView :
	public View
{
private:

	// save as a member a pointer to a longin struct
	LoginStruct * loginStructPtr;

	// selected menu option
	int selected = 0;

	// method for showing this view
	void show(std::string prompt, bool showCreateNew);

	// helper methods
	Account* getAccountFromFile(int account_id);
	Account* selectedAccount;

public:

	// Constructor
	AccountOverviewView(LoginStruct * loginStruct, bool showCreateNew, std::string prompt = "");

	// Flag for parent view or module
	bool createNewSelected = false;

	// inline functions for returning values
	int getSelected() const {
		return selected;
	}
	Account* getSelectedAccount() const {
		return selectedAccount;
	}
};

