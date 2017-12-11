#include "stdafx.h"
#include "AccountOverviewView.h"
#include "NumberFormatter.h"
#include "LoginStruct.h"
#include <string>
#include <fstream>
#include <vector>
#include <memory>


AccountOverviewView::AccountOverviewView(LoginStruct* loginStructPtrParam)
{

	loginStructPtr = loginStructPtrParam;
	show();
}
void AccountOverviewView::show() {

	std::string welcomeMsg = "Welcome ";
	welcomeMsg = welcomeMsg + loginStructPtr->username + "!";

	// Get's middle X position based on user prompt
	int xPosition = PROMPT_X;


	// Prints out the prompt for the user
	mvwprintw(getWin(), PROMPT_Y, xPosition, welcomeMsg.c_str());

	std::vector<std::string> choices;

	for (int i = 0; i < MAX_ACCOUNTS; i++) {

		if (loginStructPtr->accounts[i] > 0) {
			Account* account = getAccountFromFile(loginStructPtr->accounts[i]);
			NumberFormatter numFormatter;
			std::string balance = "$" + numFormatter.convert_to_two_decimal_string(account->balance);
			std::string str_account_id = std::to_string(account->id);
			switch (account->type) {
			case Checking:
				choices.push_back("Checking [" + str_account_id + "] " + balance);
				break;
			case Savings:
				choices.push_back("Savings [" + str_account_id + "] " + balance);
				break;
			case CD:
				choices.push_back("CD [" + str_account_id + "] " + balance);
				break;
			}
			delete account;
		}
	}
	choices.push_back("       [-- Create A New Account --]");
	int choices_len = choices.size();

	int choice = 0;
	int yPosition = PROMPT_Y;

	keypad(getWin(), true);
	curs_set(0);
	while (true) {
		for (int i = 0; i < choices_len; i++) {
			if (i == selected) {
				wattron(getWin(), A_REVERSE);
			} 
			mvwprintw(getWin(), yPosition + i + 2, xPosition, choices[i].c_str());
			wattroff(getWin(), A_REVERSE);

		}
		choice = wgetch(getWin());

		switch (choice) {
		case KEY_UP :
		case 107 :
			selected--;
			if (selected == -1) {
				selected = 0;
			}
			break;
		case KEY_DOWN :
		case 106 :
			selected++;
			if (selected == choices_len) {
				selected = choices_len - 1;
			}
			break;
		case 9 :
			selected++;
			if (selected == choices_len) {
				selected = 0;
			}
			break;
		default:
			break;
		}
		if (choice == 10) {
			curs_set(1);
			createNewSelected = (selected == choices_len - 1);
			if (selected < choices_len - 1) {
				selectedAccount = getAccountFromFile(loginStructPtr->accounts[selected]);
			}
			break;
		}
	}
}
Account* AccountOverviewView::getAccountFromFile(int account_id) {
	std::string fileName = "db/account_";
	fileName += std::to_string(account_id);
	fileName += ".dat";

	std::fstream accountFile;
	accountFile.open(fileName, std::ios::in | std::ios::binary);

	if (accountFile) {

		Account* account = new Account;
		accountFile.read(reinterpret_cast<char *>(account), sizeof(*account));
		return account;
	}
	else {
		return nullptr;
	}
}
AccountOverviewView::~AccountOverviewView()
{
}