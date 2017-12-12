#include "stdafx.h"
#include "NewAccountModule.h"
#include <fstream>
#include <iostream>
#include "AccountTypeSelectView.h"
#include "LoginStructFileWriter.h"
#include "AccountStructFileWriter.h"


// Constructor
NewAccountModule::NewAccountModule(LoginStruct *loginStruct)
{

	// This will list the types of accounts, we want to know
	// firstly what kind of account they want to create
	AccountTypeSelectView atsv;

	// as long as we're less than 4 (it's an account type)
	// 4 is the go back
	if(atsv.getSelected() < 4) {

		// Dynamically allocate an account struct
		Account* account = new Account;

		// create out input/output files
		std::ifstream accountFileIn;
		std::ofstream accountFileOut;

		// open up the incrementor file to get
		// the next number in there
		accountFileIn.open(ACCOUNT_INC_FILE);

		// read the id into our Account
		accountFileIn >> account->id;

		// close the file, we should be done with it now
		accountFileIn.close();

		// let's make sure there's even a file with an int init
		// if we didn't read the file it'll be 0;
		if (account->id > 0) {

			// increment it
			account->id++;
		}
		else {
			// set it to 1 if it's not bigger than 0
			account->id = 1;
		}

		// open the file again to write the new int to it
		accountFileOut.open(ACCOUNT_INC_FILE);
		accountFileOut << account->id;
		accountFileOut.close();


		// what type of account was selected
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

		// the account number is added to the loginStructs accounts
		loginStruct->accounts[loginStruct->num_accounts] = account->id;

		// say we have one more account in the loginStruct
		loginStruct->num_accounts++;

		// set the initial balance
		account->balance = 0.00;

		// write the account out to disk
		AccountStructFileWriter accountStructWriter(account);
		accountStructWriter.write();

		// write the updated loginSTruct to disk
		LoginStructFileWriter loginStructWriter(loginStruct);
		loginStructWriter.write();

		// get rid of it now so we don't have a reference lying around
		delete account;
	}
}
