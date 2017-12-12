#pragma once
#include "LoginStruct.h"
#include <fstream>
#include <stack>
#include <list>

class LoginModule 
{

private:

	// our reference to the login struct we will populate
	LoginStruct* loginStruct;

	// process flow functions
	void loadUserFile();
	void showPINInputView(LoginStruct*);
	void showLoginView();

	// cap login attempts at 3
	static const int MAXIMUM_LOGIN_ATTEMPTS = 3;
	

public:

	// constructor
	LoginModule();

	// inline method for returning the loginStructPtr
	LoginStruct * getLoginStructPtr() const
	{
		return loginStruct;
	}
};

