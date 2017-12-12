#pragma once
#include "LoginStruct.h"
#include "TransactionFileHandler.h"
#include "NumberFormatter.h"


class AccountModule 
{
private:

	// some flags 
	bool createNewSelected = false;
	int selected;

	// utilities
	TransactionFileHandler transactionFile;
	NumberFormatter numFormatter;

	// shows the different views
	void showDepositView(Account* account);
	void showTransferView(Account * account,  LoginStruct * loginStruct);
	void showWithdrawalView(Account * account);
	void showBalanceView(Account * account);
	void showTransactionHistory(Account * account);
	void showAccountOverviewView(LoginStruct*);
	void showAccountDetail(Account * account,  LoginStruct * loginStruct);

public:

	// constructor
	AccountModule(LoginStruct*);


	// inline functions for returning private
	// member values
	bool getCreateNewSelected() const
	{
		return createNewSelected; 
	}
	int getSelected() const {
		return selected;
	}
};

