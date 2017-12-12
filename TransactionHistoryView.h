#pragma once
#include "View.h"
#include "Account.h"
#include <string>

// view that displays the transaction history log view
class TransactionHistoryView :
	public View
{
public:

	// Constructor with which account history to get
	TransactionHistoryView(Account * account);
};

