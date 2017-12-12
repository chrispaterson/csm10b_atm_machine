#include "stdafx.h"
#include "HomeMenuListView.h"


// Constructs the menulist
HomeMenuListView::HomeMenuListView()
{
	createMenu(menuPrompt, menuChoices, NUM_CHOICES);
}