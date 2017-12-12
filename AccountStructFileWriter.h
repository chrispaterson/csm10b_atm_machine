#pragma once
#include "Account.h"
#include <string>

// Writes out the Account struct to a binary
// file on disk
class AccountStructFileWriter
{
private:

	// keep a reference to the pointer for the account
	Account *accountStructPtr;

	// keep filename to write to and read from
	std::string fileName;

public:

	// constructor
	AccountStructFileWriter(Account* accountStruct);

	// check whether the file already exists
	bool exists();

	// write to the file
	bool write();
};

