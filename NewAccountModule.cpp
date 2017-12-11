#include "stdafx.h"
#include "NewAccountModule.h"
#include <fstream>
#include <iostream>
#include "AccountTypeSelectView.h"
#include "helper_write_loginstruct.h"


NewAccountModule::NewAccountModule(LoginStruct *loginStruct)
{
	Account* account = new Account;
	std::ifstream accountFileIn;
	std::ofstream accountFileOut;
	accountFileIn.open(ACCOUNT_INC_FILE);


	accountFileIn >> account->id;
	accountFileIn.close();
	if (account->id > 0) {
		account->id++;
	}
	else {
		account->id = 1;
	}
	accountFileOut.open(ACCOUNT_INC_FILE);
	accountFileOut << account->id;
	accountFileOut.close();

	AccountTypeSelectView atsv;

	switch (atsv.getSelected()) {
	case 0:
		account->type = Checking;
		break;
	case 1:
		account->type = Savings;
		break;
	case 2:
		account->type = CD;
		break;
	}

	loginStruct->accounts[loginStruct->num_accounts] = account->id;
	loginStruct->num_accounts++;

	account->balance = 0.00;

	std::fstream accountStructFile;
	std::string fileName = "db/account_" ;
	fileName += std::to_string(account->id);
	fileName += ".dat";

	accountStructFile.open(fileName, std::ios::out | std::ios::binary);
	accountStructFile.write(reinterpret_cast<char *>(account), sizeof(*account));
	accountStructFile.close();

	helper_write_loginstruct loginStructWriter(loginStruct);
	loginStructWriter.write();

	delete account;

}


NewAccountModule::~NewAccountModule()
{
}
