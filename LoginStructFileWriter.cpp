#include "stdafx.h"
#include "LoginStructFileWriter.h"
#include <fstream>


// constructor takes a loginStruct pointer to keep track
// of the dynamically allocated struct
LoginStructFileWriter::LoginStructFileWriter(LoginStruct *loginStruct)
{

	// save the reference
	loginStructPtr = loginStruct;

	// make our file name
	fileName = loginStruct->username;
	fileName = "db/" + fileName;
	fileName += ".dat";
}

// writes the struct to a binary file
bool LoginStructFileWriter::write() {

	// our file stream object
	std::fstream userFile;

	// open it in binary and overwrite whatever is in there
	userFile.open(fileName, std::fstream::out | std::fstream::binary | std::fstream::trunc);

	// write it out
	userFile.write(reinterpret_cast<char *>(loginStructPtr), sizeof(*loginStructPtr));
	
	// close out the file
	userFile.close();

	// return whether or not it worked
	return !!userFile;
}

// does the file exists already?
bool LoginStructFileWriter::exists() {

	// return whether it exists
	return !!std::ifstream(fileName);
}