#include "stdafx.h"
#include "UserCreationModule.h"
#include "LoginView.h"
#include "LoginStruct.h"
#include "DisplayMesageView.h"
#include "PINInputView.h"
#include <fstream>
#include <string>
#include <ios>
#include <iostream>
#include "helper_write_loginstruct.h"


UserCreationModule::UserCreationModule()
{
	bool userCreated = false;

	while(!userCreated) {

		showLoginView();
		showPINInputView();
		userCreated = createUserFile();
	}
}
UserCreationModule::~UserCreationModule()
{
}
char * UserCreationModule::getUsername()
{
	return loginStruct.username;
}

int * UserCreationModule::getPIN()
{
	return &loginStruct.pin;
}

void UserCreationModule::showLoginView() {

	LoginView loginView(getUsername(), USERNAME_SIZE);
}
void UserCreationModule::showPINInputView() {

	PINInputView pinInputView(&loginStruct.pin, PIN_SIZE);
}
bool UserCreationModule::createUserFile() {

	helper_write_loginstruct writer(&loginStruct);
	DisplayMesageView dmv;

	if (writer.exists()) {

		// user already exists!!
		dmv.displayMessage("That User exists already.  Press [Enter] to try again");
		return false;
	}

	return writer.write();
}
