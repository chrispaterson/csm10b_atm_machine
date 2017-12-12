#include "stdafx.h"
#include "AccountTypeSelectView.h"


AccountTypeSelectView::AccountTypeSelectView()
{
	// calls base class method for creating a menu
	createMenu(prompt, accountTypes, NUM_ACCOUNT_TYPES);
}