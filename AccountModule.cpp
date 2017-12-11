#include "stdafx.h"
#include "AccountModule.h"
#include "Account.h"
#include "AccountOverViewView.h"
#include "LoginStruct.h"
#include "AccountDetailView.h"
#include <iostream>


AccountModule::AccountModule(LoginStruct* loginStructPtr)
{
	showAccountOverviewView(loginStructPtr);
}
void AccountModule::showAccountOverviewView(LoginStruct* loginStructPtr) {

	AccountOverviewView accountOverViewView(loginStructPtr);
	if (accountOverViewView.createNewSelected) {

		// just return naturally setting our flag
		createNewSelected = true;
	}
	else {
		selected = accountOverViewView.getSelected();
		showAccountDetail(accountOverViewView.getSelectedAccount());

	}
}
void AccountModule::showAccountDetail(Account* account) {

		AccountDetailView adv(account);
		switch (adv.getSelected()) {
			// deposit
		case 0:
			break;

			//withdrawal
		case 1:
			break;

			// Get Balance
		case 2:
			break;

			// Transfer
		case 3:
			break;
		}
}
AccountModule::~AccountModule()
{
}
