#pragma once
#include "InputView.h"

class LoginView :
	public InputView {

public:

	// constructor takes user and it's size
	LoginView(char * username, int username_size);

};