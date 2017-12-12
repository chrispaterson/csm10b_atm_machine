#pragma once
#include "LoginStruct.h"

// class for creating a new user

class UserCreationModule 
{
private:
	// reference to the login struct Ptr
	LoginStruct* loginStruct;

	// internal flow functions
	void showLoginView();
	void showPINInputView();
	bool createUserFile();

public:

	// constructor
	UserCreationModule();

	// inline function for returning the login struct pointer
	LoginStruct* getLoginStructPtr() {
		return loginStruct;
	}
};

