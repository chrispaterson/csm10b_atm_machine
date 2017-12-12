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
#include "LoginStructFileWriter.h"


// constructor
UserCreationModule::UserCreationModule()
{

	// whether or not the user was created
	bool userCreated = false;

	// dynamically allocate a new loginStruct
	loginStruct = new LoginStruct;
	loginStruct->username[loginStruct->USERNAME_SIZE] = {};

	// use a loop to make sure we create the user
	while(!userCreated) {

		// show the loginView to get username
		showLoginView();

		// get the new pin number
		showPINInputView();

		// create the file, maybe?
		userCreated = createUserFile();
	}
}

// login view asks for the username
void UserCreationModule::showLoginView() {

	// pass the login struct members
	LoginView loginView(loginStruct->username, loginStruct->USERNAME_SIZE);
}

// get pin input
void UserCreationModule::showPINInputView() {

	// pass the login struct members
	PINInputView pinInputView(&loginStruct->pin, loginStruct->PIN_SIZE);
}
bool UserCreationModule::createUserFile() {

	// use the utility for writing
	LoginStructFileWriter writer(loginStruct);

	// in case we need to display a message
	DisplayMesageView dmv;

	// did the user exist already?  If yes we can't create
	// a new one
	if (writer.exists()) {

		// user already exists!!
		dmv.displayMessage("That User exists already.  Press [Enter] to try again");
		return false;
	}

	// if not, then hopefully we can write to it
	return writer.write();
}
