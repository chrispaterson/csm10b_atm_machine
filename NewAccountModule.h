#pragma once
#include "Module.h"
#include "LoginStruct.h"
#include "Account.h"
#include <string>

class NewAccountModule :
	public Module
{

private:
	const std::string ACCOUNT_INC_FILE = "accounts_inc.txt";

public:
	NewAccountModule(LoginStruct *loginStruct);
	~NewAccountModule();
};

