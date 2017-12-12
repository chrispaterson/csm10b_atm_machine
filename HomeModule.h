#pragma once

// creates the views for the home screen
class HomeModule 
{

private:
	int selected = 0;

public:

	// constructor
	HomeModule();

	// inline function that returns which option was selected
	int getSelected() const {
		return selected;
	}
};

