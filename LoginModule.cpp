#include "stdafx.h"
#include "LoginModule.h"
#include "LoginView.h"
#include "PINInputView.h"
#include "View.h"
#include <fstream>
#include "LoginStruct.h"
#include <fstream>
#include "DisplayMesageView.h"
#include <iostream>
#include <chrono>
#include <thread>


LoginModule::LoginModule()
{
	loginStruct = new LoginStruct;
	loginStruct->username[USERNAME_SIZE] = {};
	showLoginView();
}

void LoginModule::showLoginView() {

	LoginView loginView(loginStruct->username, USERNAME_SIZE);
	loadUserFile();
}

void LoginModule::loadUserFile() {

	string fileName = loginStruct->username;
	fileName = "db/" + fileName;
	fileName += ".dat";
	fstream userFile;
	userFile.open(fileName, std::ios::in | std::ios::binary);

	if (userFile) {

		LoginStruct* fileLoginStruct = new LoginStruct;
		userFile.read(reinterpret_cast<char *>(fileLoginStruct), sizeof(*fileLoginStruct));
		showPINInputView(fileLoginStruct);
	}
	else {

		// Load incorrect User View
		DisplayMesageView displayMessage;
		displayMessage.displayMessage("Username not found!");
		showLoginView();
	}
	
}
void LoginModule::showPINInputView(LoginStruct* loginStructFromFile) {

	static int attempts = 0;

	// Ask for PIN
	PINInputView pinInputView(&loginStruct->pin, PIN_SIZE);
	attempts++;
	if (loginStructFromFile->pin == loginStruct->pin ) {
		// correct PIN Number
		// let it return naturally
		delete loginStruct;
		loginStruct = loginStructFromFile;

	}
	else {
		// Incorrect PIN Number
		if (attempts <= MAXIMUM_LOGIN_ATTEMPTS) {

			showPINInputView(loginStructFromFile);
		}
		else {

			DisplayMesageView displayMessage;
			displayMessage.displayMessage("Sorry, too many incorrect attempts");
			exit(EXIT_SUCCESS);
		}

	}
}
void LoginModule::setUsername(char* username) {
	strcpy_s(loginStruct->username, USERNAME_SIZE, username);
};
void LoginModule::setPIN(int pin) {
	loginStruct->pin = pin;
};
int* LoginModule::getPIN() {
	return &loginStruct->pin;
};

LoginModule::~LoginModule()
{
}

LoginStruct * LoginModule::getLoginStructPtr()
{
	return loginStruct;
}
