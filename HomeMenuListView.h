#pragma once
#include "MenuListView.h"
#include <string>

// Just has the two options to either create a new user or login
// as an existing user
class HomeMenuListView :
	public MenuListView
{
private:

	// menu option choices 
	const static int NUM_CHOICES = 2;
	std::string menuChoices[NUM_CHOICES] = {"Log in" , "New User" };

	// the prompt
	std::string menuPrompt = "Welcome!";

public:

	// Constructor
	HomeMenuListView();
};

