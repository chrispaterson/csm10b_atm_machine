#include "stdafx.h"
#include "HomeModule.h"
#include "HomeMenuListView.h"


HomeModule::HomeModule()
{

	HomeMenuListView hmlv;
	selected = hmlv.getSelected();
}


HomeModule::~HomeModule()
{
}

int HomeModule::getSelected()
{
	return selected;
}
