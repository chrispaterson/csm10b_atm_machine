#include "stdafx.h"
#include "AccountModule.h"
#include "Account.h"
#include "AccountOverViewView.h"
#include "LoginStruct.h"
#include "AccountDetailView.h"
#include "DisplayMesageView.h"
#include "AccountStructFileWriter.h"
#include "MoneyInputView.h"
#include "TransactionHistoryView.h"
#include <iostream>
#include <sstream>


AccountModule::AccountModule(LoginStruct* loginStructPtr)
{
	showAccountOverviewView(loginStructPtr);
}

// builds account overview
void AccountModule::showAccountOverviewView(LoginStruct* loginStructPtr) {

	//show our view -- lists the accounts
	AccountOverviewView accountOverViewView(loginStructPtr, true);

	// One of the items in the list is create new we will throw that
	// back up to the Controller to handle
	if (accountOverViewView.createNewSelected) {

		// just return naturally setting our flag
		createNewSelected = true;
	}
	else {

		// if one not new selected then we get which account
		// was selected
		selected = accountOverViewView.getSelected();

		// Pass the selected account struct into the account
		// detail view
		showAccountDetail(accountOverViewView.getSelectedAccount(), loginStructPtr);
	}
}
void AccountModule::showAccountDetail(Account* account, LoginStruct * loginStruct) {

	// pass the account struct pointer to the account detail
	// view
	AccountDetailView adv(account);

	// create an instance of our transaction file writer
	// we want to log all things that happen with this
	// account into a log file
	transactionFile.setAccount(account);

	// Get the selected value from the account detail view
	// these are basically menu options
	switch (adv.getSelected()) {
	case 0:

		// Deposit
		showDepositView(account);
		break;
	case 1:

		// Withdrawal
		showWithdrawalView(account);
		break;
	case 2:

		// Balance
		showBalanceView(account);
		break;
	case 3:

		// Transfer
		showTransferView(account, loginStruct);
		break;
	case 4:

		// Transaction History
		showTransactionHistory(account);
		break;
	}
}

// does what it says takes account pointer 
void AccountModule::showDepositView(Account * account) {

	// use a money input to capture the amount
	// the user wants to deposit
	MoneyInputView miv("deposit");

	// add to our balance
	account->balance += miv.getAmount();

	// write the account out to disk
	AccountStructFileWriter asfw(account);
	asfw.write();

	// write a log in the transaction list
	transactionFile.writeLn("$" + numFormatter.convert_to_two_decimal_string(miv.getAmount()) + " Deposit");
}

// does what it says takes account pointer but we also need
// the loginstruct to find the other available accounts
void AccountModule::showTransferView(Account * account, LoginStruct * loginStruct) {

	// use a money input to capture the amount
	// the user wants to transfer
	MoneyInputView miv("transfer");

	// capture the amount they entered
	double amt = miv.getAmount();

	// let's just make sure they have the money
	if(amt <= account->balance) {

		// Now we'll use the account overview view to have
		// the user select which account they want to
		// transfer to.
		AccountOverviewView aovv(loginStruct, false, "Please select an account to transfer to");

		// when they've selected an account we need to get
		// a reference to that account
		Account * act2 = aovv.getSelectedAccount();

		// subtract the balance from this account
		account->balance -= amt;

		// add the balance to the other account
		act2->balance += amt;

		// now save the change on this account
		AccountStructFileWriter asfw1(account);
		asfw1.write();

		// save the change on the other account
		AccountStructFileWriter asfw2(act2);
		asfw2.write();

		// write a log in the transactions file for this account
		transactionFile.writeLn("$" + numFormatter.convert_to_two_decimal_string(amt) + " Transfer to Account: " + std::to_string(act2->id));

		// create a special file handler fot the other account to 
		// write a log file line
		TransactionFileHandler tfh2;
		tfh2.setAccount(act2);
		tfh2.writeLn(std::to_string(amt) + " Transfer from Account: " + std::to_string(account->id));

		// get rid of the second account pointer
		delete act2;
	}
	else {

		// oh! you don't have the money
		// Display Mesage View just shows one line of text
		DisplayMesageView dmv;
		dmv.displayMessage("Insufficient Funds");
	}

}
void AccountModule::showWithdrawalView(Account * account) {

	// use a money input to capture the amount
	// the user wants to withdrawal
	MoneyInputView miv("withdrawal");

	// save the amount
	double withdrawalAmount = miv.getAmount();

	// make sure we have the money
	if(withdrawalAmount <= account->balance) {

		// subtract the amount from out balance
		account->balance -= withdrawalAmount;

		// save the change
		AccountStructFileWriter asfw(account);
		asfw.write();

		// write a log line
		transactionFile.writeLn("$" + numFormatter.convert_to_two_decimal_string(withdrawalAmount) + " Withdrawal");
	}
	else {

		// oh! you don't have the money
		// Display Mesage View just shows one line of text
		DisplayMesageView dmv;
		dmv.displayMessage("Insufficient Funds");
	}

}

void AccountModule::showBalanceView(Account * account) {

	// just shows the balance
	DisplayMesageView dmv;
	std::string balance = "$" + numFormatter.convert_to_two_decimal_string(account->balance);
	dmv.displayMessage(balance + " Balance");
}

void AccountModule::showTransactionHistory(Account * account) {

	// shows the transaction log
	TransactionHistoryView thv(account);
}