#pragma once
#include "InputView.h"
#include <string>

// class asks a user how much money they would like to [blank]
class MoneyInputView :
	public InputView
{

private:
	// no more than 20 places
	const static int INPUT_LIMIT = 20;
	char input[INPUT_LIMIT];

	// the display for the type of money action, deposit, withdrawal etc...
	std::string transaction_verb;

	//inline private function for generating the Prompt
	std::string getPrompt() const
	{
		return "Please enter a " + transaction_verb + " amount";
	}

	// set the string of the money type, privately
	void setTransactionVerb(std::string transactionVerb) {
		transaction_verb = transactionVerb;
	}

public:

	// Constructor
	MoneyInputView(std::string transactionVerb);

	// inline function for returning the double value of the input
	double getAmount() const
	{
		return atof(input);
	}
};

