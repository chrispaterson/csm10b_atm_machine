#pragma once
#include "module.h"
#include "LoginStruct.h"
#include <fstream>
#include <stack>
#include <list>

using namespace std;

class LoginModule :
	public Module
{

private:

	LoginStruct* loginStruct;

	void loadUserFile();
	void showPINInputView(LoginStruct*);
	void setUsername(char*);
	char* getUsername();
	void setPIN(int);
	int* getPIN();
	void showLoginView();

	static const int MAXIMUM_LOGIN_ATTEMPTS = 3;
	

public:

	LoginModule();
	~LoginModule();
	LoginStruct* getLoginStructPtr();
};

