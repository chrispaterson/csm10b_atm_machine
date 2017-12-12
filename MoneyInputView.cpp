#include "stdafx.h"
#include "MoneyInputView.h"


// generates the display
// transactionVerb: deposit, withdrawal, transfer, etc...
MoneyInputView::MoneyInputView(std::string transactionVerb)
{
	// set our verb so the prompt works
	setTransactionVerb(transactionVerb);

	// same as input view
	generateSingleInput(getPrompt(), input, INPUT_LIMIT);
}