#include "stdafx.h"
#include "AccountOverviewView.h"
#include "NumberFormatter.h"
#include "LoginStruct.h"
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>
#include <memory>


AccountOverviewView::AccountOverviewView(LoginStruct* loginStructPtrParam, bool showCreateNew, std::string prompt)
{

	loginStructPtr = loginStructPtrParam;
	show(prompt, showCreateNew);
}
void AccountOverviewView::show(std::string prompt, bool showCreateNew) {

	std::vector<std::string> choices;

	Account totalAccount;
	totalAccount.balance = 0.0;
	totalAccount.id = 0;

	NumberFormatter numFormatter;

	for (int i = 0; i < loginStructPtr->MAX_ACCOUNTS; i++) {

		if (loginStructPtr->accounts[i] > 0) {
			Account* account = getAccountFromFile(loginStructPtr->accounts[i]);
			if (account != nullptr) {

				totalAccount += *account;

				std::string balance = "$" + numFormatter.convert_to_two_decimal_string(account->balance);
				std::string str_account_id = std::to_string(account->id);
				std::string accountType;
				switch (account->type) {
				case Checking:
					accountType = "Checking";
					break;
				case Savings:
					accountType = "Savings";
					break;
				case CD:
					accountType = "CD";
					break;
				}

				std::ostringstream sstream;
				sstream << std::setw(8) << accountType;
				sstream << std::setw(8) << '#' << account->id;
				sstream << std::right << std::setw(10) << '$' << std::fixed << std::setprecision(2) << account->balance;
				choices.push_back(sstream.str());

				delete account;
			}
		}
	}
	if(showCreateNew) {
		choices.push_back("-> Create a new Account");
	}
	choices.push_back("<- Exit");
	int choices_len = choices.size();

	int choice = 0;

	int xPosition = PROMPT_X;
	int yPosition = PROMPT_Y;

	if (prompt == "") {
		prompt = "Welcome ";
		prompt += loginStructPtr->username;
		prompt += "! [$";
		prompt += numFormatter.convert_to_two_decimal_string(totalAccount.balance);
		prompt += "]";
	}
	// Prints out the prompt for the user
	mvwprintw(getWin(), PROMPT_Y, xPosition, prompt.c_str());

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
			if (showCreateNew) {
				createNewSelected = (selected == choices_len - 2);
				if (selected < choices_len - 2) {
					selectedAccount = getAccountFromFile(loginStructPtr->accounts[selected]);
				}
				else if (selected == choices_len - 1) {
					exit(0);
				}
			}
			else {
				if(selected < choices_len - 1) {
					selectedAccount = getAccountFromFile(loginStructPtr->accounts[selected]);
				}
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
