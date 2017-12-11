#include "stdafx.h"
#include "AccountTypeSelectView.h"


AccountTypeSelectView::AccountTypeSelectView()
{
	createMenu(prompt, accountTypes, NUM_ACCOUNT_TYPES);
}


AccountTypeSelectView::~AccountTypeSelectView()
{
}
