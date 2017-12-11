#pragma once
#include "InputView.h"
#include <string>
#include "LoginStruct.h"

class CreateUsernameView :
	public InputView
{
private:
	char* getUsername();
	char* getPIN();

public:

	CreateUsernameView(std::string prompt,  std::string username);
	~CreateUsernameView();
};

