#pragma once
#include "LoginModule.h"
#include "LoginStruct.h"

class Controller
{

private:
	// Login
	void showLoginModule();

	// create a user
	void showUserCreationModule();

	// show the account
	void showAccountModule(LoginStruct * loginStruct);

public:

	// Constructor
	Controller();
};

