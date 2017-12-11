#pragma once
#include "Module.h"
#include "LoginStruct.h"


class AccountModule :
	public Module
{
private:
	bool createNewSelected = false;
	int selected;
public:
	AccountModule(LoginStruct*);
	void showAccountOverviewView(LoginStruct*);
	void showAccountDetail(Account * account);
	bool getCreateNewSelected() const
	{
		return createNewSelected; 
	}
	int getSelected() const {
		return selected;
	}
	~AccountModule();
};

