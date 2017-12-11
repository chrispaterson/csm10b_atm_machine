#include "stdafx.h"
#include "AccountDetailView.h"
#include "NumberFormatter.h"
#include "DisplayMesageView.h"
#include <string>
#include <iostream>


AccountDetailView::AccountDetailView(Account *account)
{
	if(account != nullptr) {
		show(account);
	}
	else {
		std::cout << "No acount!!!!" << std::endl;
		throw "No account!";
	}
}

void AccountDetailView::show(Account *account) {

	std::string prompt;

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

	NumberFormatter numFormatter;

	std::string balance = "$" + numFormatter.convert_to_two_decimal_string(account->balance);
	prompt += " [" + std::to_string(account->id) + "] " + balance;

	createMenu(prompt, actions, NUM_CHOICES);
    switch(getSelected()) {
      case 0:
        // Deposit
        break;
      case 1:
        // Withdrawal
        break;
      case 2:
        // Balance
        DisplayMesageView dmv;
        dmv.displayMessage(balance + " Balance");
        break;
      case 3:
        // Transfer
        break;
    }
}

AccountDetailView::~AccountDetailView()
{
}
