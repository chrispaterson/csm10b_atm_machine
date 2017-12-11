#include "stdafx.h"
#include "helper_write_loginstruct.h"
#include <fstream>


helper_write_loginstruct::helper_write_loginstruct(LoginStruct *loginStruct)
{

	loginStructPtr = loginStruct;
	fileName = loginStruct->username;
	fileName = "db/" + fileName;
	fileName += ".dat";

}
bool helper_write_loginstruct::write() {
	std::fstream userFile;

	userFile.open(fileName, std::fstream::out | std::fstream::binary | std::fstream::trunc);
	userFile.write(reinterpret_cast<char *>(loginStructPtr), sizeof(*loginStructPtr));
	userFile.close();

	return !!userFile;
}
bool helper_write_loginstruct::exists() {
	return !!std::ifstream(fileName);
}


helper_write_loginstruct::~helper_write_loginstruct()
{
}
