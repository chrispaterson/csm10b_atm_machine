#include "stdafx.h"
#include "Controller.h"
#include "curses.h"
#include "LoginModule.h"
#include "LoginStruct.h"
#include "AccountModule.h"
#include "DisplayMesageView.h"
#include "HomeModule.h"
#include "UserCreationModule.h"
#include "NewAccountModule.h"
#include <memory>
#include <iostream>

Controller::Controller()
{
	initscr();
	cbreak();

	mvprintw(1, 3, "Bank of CS M10B");

	std::unique_ptr<HomeModule> homeModule(new HomeModule());

	// login
	if (homeModule->getSelected() == 0) {
		showLoginModule();
	}
	// Create a new user
	else {
		showUserCreationModule();
	}
}
void Controller::showLoginModule() {
	std::unique_ptr<LoginModule> loginModule(new LoginModule());
	showAccountModule(loginModule->getLoginStructPtr());
}
void Controller::showUserCreationModule() {
	std::unique_ptr<UserCreationModule> dmv(new UserCreationModule());
	showLoginModule();
}

void Controller::showAccountModule(LoginStruct* loginStruct) {
	while(true) {
		AccountModule accountModule(loginStruct);
		if (accountModule.getCreateNewSelected()) {

			NewAccountModule newAccountModule(loginStruct);
		}
	}
}