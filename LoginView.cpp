#include "stdafx.h"
#include "LoginView.h"

// Constructor for creating the Login View
LoginView::LoginView(char* username, int username_size) : InputView()
{
	// send prompt get input
	generateSingleInput("Please enter user ID", username, username_size);
}

