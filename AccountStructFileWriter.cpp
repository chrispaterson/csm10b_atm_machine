#include "stdafx.h"
#include "AccountStructFileWriter.h"
#include <fstream>


AccountStructFileWriter::AccountStructFileWriter(Account* account)
{

	// save ptr
	accountStructPtr = account;

	// make our filename
	fileName = std::to_string(account->id);
	fileName = "db/account_" + fileName;
	fileName += ".dat";

}

// method to write to the file with the correct settings
bool AccountStructFileWriter::write() {

	// create our input stream
	std::fstream file;

	// open the file in binary for output and overwrite anything that is there
	file.open(fileName, std::fstream::out | std::fstream::binary | std::fstream::trunc);

	// write the binary file out
	file.write(reinterpret_cast<char *>(accountStructPtr), sizeof(*accountStructPtr));

	// close the file
	file.close();

	//we succeeded
	return !!file;
}

// returns whether the file exists or not
bool AccountStructFileWriter::exists() {
	return !!std::ifstream(fileName);
}