#pragma once
#include "LoginStruct.h"
#include "Account.h"
#include <string>


// Module for the account
class NewAccountModule 
{

private:

	// file for the account number incrementor will have just
	// a number in it that we will read and increment
	const std::string ACCOUNT_INC_FILE = "accounts_inc.txt";

public:

	// Constructor just takes a pointer to the loginStruct
	NewAccountModule(LoginStruct *loginStruct);
};

