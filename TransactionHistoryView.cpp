#include "stdafx.h"
#include <fstream>
#include "TransactionHistoryView.h"
#include "TransactionFileHandler.h"
#include <vector>


// view that displays the transactions log
TransactionHistoryView::TransactionHistoryView(Account * account)
{

	// create a vector to read the lines of the log into
	std::vector<std::string> transactions;

	// variable for storing account type
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

	// Create our header string
	std::string header = "Transaction history for " + accountType + " #" + std::to_string(account->id);

	// mv and print the header
	mvwprintw(getWin(), getPadding(),  getPadding(), header.c_str());

	// to open and rad the file
	TransactionFileHandler tfh;
	tfh.setAccount(account);
	std::ifstream file = tfh.read();

	// variable for the line
	std::string line;

	// loop through and push each line to the vector
	while (std::getline(file, line)) {
		transactions.push_back(line);
	}

	// this is the lower bounds of our view
	int yBounds = getYMax() - 2*getPadding() - 6;

	// print newest on top by loping backwards
	for (int i = transactions.size() - 1, j=0; i >= 0; i--, j++) {

		// if we're higher than our yBounds justbreak out of the loop
		if (j > yBounds) {
			break;
		}
		// print the line
		mvwprintw(getWin(), getPadding() + j + 2, getPadding(), transactions[i].c_str());
	}

	// move cursor to end
	mvwin(getWin(), yBounds + 1, getPadding());

	//wait for a key press
	wgetch(getWin());
}
