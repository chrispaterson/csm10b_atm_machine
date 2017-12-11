#pragma once
#include "LoginStruct.h"
#include <string>

class helper_write_loginstruct
{
private:
	LoginStruct *loginStructPtr;
	std::string fileName;

public:
	helper_write_loginstruct(LoginStruct *loginStruct);
	~helper_write_loginstruct();
	bool exists();
	bool write();
};

