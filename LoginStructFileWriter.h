#pragma once
#include "LoginStruct.h"
#include <string>

// writes a login struct to a binary file
class LoginStructFileWriter
{

private:

	// keep reference to loginStruct 
	LoginStruct *loginStructPtr;

	// save our file name
	std::string fileName;

public:

	// constructor
	LoginStructFileWriter(LoginStruct *loginStruct);

	// shortcut to tell if the file already exists
	bool exists();

	// writes out the file
	bool write();
};

