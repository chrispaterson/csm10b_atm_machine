#pragma once
#include "View.h"
#include <string>
class InputView :
	public View
{
protected:
	void generateSingleInput(std::string, char* input, int inputSize);
};

