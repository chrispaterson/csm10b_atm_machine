#pragma once
#include "Module.h"
#include "LoginStruct.h"

class UserCreationModule :
	public Module
{
private:
	LoginStruct loginStruct;
	char* getUsername();
	int* getPIN();

	void showLoginView();

	void showPINInputView();

	bool createUserFile();

public:
	UserCreationModule();
	~UserCreationModule();
};

