#pragma once
#include "MenuListView.h"
#include <string>

class HomeMenuListView :
	public MenuListView
{
private:
	const static int NUM_CHOICES = 2;
	std::string menuChoices[NUM_CHOICES] = {"Log in" , "New User" };
	std::string menuPrompt = "Welcome!";

public:
	HomeMenuListView();
	~HomeMenuListView();
};

