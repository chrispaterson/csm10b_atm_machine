#pragma once
#include "Module.h"
class HomeModule :
	public Module
{
private:
	int selected = 0;

public:
	HomeModule();
	~HomeModule();
	int getSelected();
};

