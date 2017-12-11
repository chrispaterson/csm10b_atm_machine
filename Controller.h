#pragma once
#include "LoginModule.h"
#include "LoginStruct.h"

class Controller
{
private:
public:
	Controller();
	void showLoginModule();
	void showUserCreationModule();
	void showAccountModule(LoginStruct * loginStruct);
};

