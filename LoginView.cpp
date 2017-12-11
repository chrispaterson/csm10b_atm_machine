#include "stdafx.h"
#include "LoginView.h"
#include <string>

using namespace std;

LoginView::LoginView(char* username, int username_size) : InputView()
{
	generateSingleInput("Please enter user ID", username, username_size);
}

