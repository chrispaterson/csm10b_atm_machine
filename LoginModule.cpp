#include "stdafx.h"
#include <fstream>
#include <fstream>
#include <iostream>
#include <chrono>
#include <thread>
#include "View.h"
#include "DisplayMesageView.h"
#include "LoginStruct.h"
#include "LoginModule.h"
#include "LoginView.h"
#include "PINInputView.h"
#include "DisplayMesageView.h"


// dynamically allocate the LoginStruct that will be used through
// this application for the user
LoginModule::LoginModule()
{
	// dynaically allocate
	loginStruct = new LoginStruct;

	// initialize the username array
	loginStruct->username[loginStruct->USERNAME_SIZE] = {};

	// move on to the loginView
	showLoginView();
}

// generates the login view
void LoginModule::showLoginView() {

	// create the loginView and capture the username
	LoginView loginView(loginStruct->username, loginStruct->USERNAME_SIZE);

	// Once we have the username we can load the file
	loadUserFile();
}

// loads the user file
void LoginModule::loadUserFile() {

	// generate our file name
	std::string fileName = loginStruct->username;
	fileName = "db/" + fileName;
	fileName += ".dat";
	std::fstream userFile;
	userFile.open(fileName, std::ios::in | std::ios::binary);

	// if the file exists and we opened it
	if (userFile) {

		// create a login struct for our loaded file
		LoginStruct* fileLoginStruct = new LoginStruct;
		userFile.read(reinterpret_cast<char *>(fileLoginStruct), sizeof(*fileLoginStruct));

		// go to the PIN input view to see if they enter the
		// correct pin number
		showPINInputView(fileLoginStruct);
	}
	else {

		// Load incorrect User View
		DisplayMesageView displayMessage;
		displayMessage.displayMessage("Username not found!");

		// try again
		showLoginView();
	}
	
}

// get the pin number
void LoginModule::showPINInputView(LoginStruct* loginStructFromFile) {

	// number of login attempts
	static int attempts = 0;

	// Ask for PIN
	PINInputView pinInputView(&loginStruct->pin, loginStruct->PIN_SIZE);
	
	// increment our attempts
	attempts++;

	// does the loaded pin number from the file match
	// the pin number that they just entered?
	if (loginStructFromFile->pin == loginStruct->pin ) {

		// correct PIN Number
		// let it return naturally
		delete loginStruct;
		
		// ok we have a success, now use the 
		// file loaded login struct
		loginStruct = loginStructFromFile;

	}
	else {

		// Incorrect PIN Number check against
		// our maximum number of attempts
		if (attempts <= MAXIMUM_LOGIN_ATTEMPTS) {

			// if we're stil within reason we'll
			// give them another shot
			showPINInputView(loginStructFromFile);
		}
		else {

			// Try to remember your PIN, display a message
			// let them know it's over
			DisplayMesageView displayMessage;
			displayMessage.displayMessage("Sorry, too many incorrect attempts");

			// bye bye
			exit(EXIT_SUCCESS);
		}

	}
}