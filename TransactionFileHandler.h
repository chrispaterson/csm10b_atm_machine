#pragma once
#include <fstream>
#include <string>
#include "Account.h"

// Class that reads and writes lines to the
// transaction log
class TransactionFileHandler
{

private:

	// reference to the account
	Account* accountPtr;

	// name of the file
	std::string filename;

public:

	// intially an account needs to be set
	void setAccount(Account * account);

	// for reading, returns the file object
	std::ifstream read();

	//  appends a single line to the file
	void writeLn(std::string);

};

