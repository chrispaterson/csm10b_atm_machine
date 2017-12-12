#pragma once
#include "View.h"
#include <string>

// Base class for generating an input with a prompt
class InputView :
	public View
{
protected:

	// meant to be subclassed, takes a string for the prompt
	// char* input is the reference to where to put the user 
	// input supplied and inputSize is the maximum number of
	// characters allowed for the input
	void generateSingleInput(std::string, char* input, int inputSize);
};

