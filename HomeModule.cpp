#include "stdafx.h"
#include "HomeModule.h"
#include "HomeMenuListView.h"


// constructor creates the home menu list and 
// sets this selection to the home menu view one
HomeModule::HomeModule()
{

	HomeMenuListView hmlv;
	selected = hmlv.getSelected();
}