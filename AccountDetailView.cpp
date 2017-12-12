#include "stdafx.h"
#include "AccountDetailView.h"
#include "NumberFormatter.h"
#include <string>
#include <iostream>


// constructor, takes Account struct pointer
AccountDetailView::AccountDetailView(Account *account)
{

	// just make sure we have something before we
	// try to display as we will have a seg fault
	// if we don't
	if(account != nullptr) {

		// all good, let's show
		show(account);
	}
	else {
		
		// oops we broke
		std::cerr << "No acount!!!!" << std::endl;
		throw "No account!";
	}
}

// show's account info and builds a menu of navigation
// options to execute.
void AccountDetailView::show(Account *account) {

	// this will be our prompt for our menu
	std::string prompt;

	// type is an enum we need a string
	switch (account->type) {
	case Checking:
		prompt = "Checking";
		break;
	case Savings:
		prompt = "Savings";
		break;
	case CD:
		prompt = "CD";
		break;
	}

	// utility for printing numbers
	NumberFormatter numFormatter;
	
	// nicely printed balance
	std::string balance = "$" + numFormatter.convert_to_two_decimal_string(account->balance);

	// show our account id and balance in the prompt
	prompt += " #" + std::to_string(account->id) + " " + balance;

	// create our menu
	createMenu(prompt, actions, NUM_CHOICES);
}
