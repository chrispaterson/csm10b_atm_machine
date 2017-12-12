#include "stdafx.h"
#include <time.h>
#include "TransactionFileHandler.h"

void TransactionFileHandler::setAccount(Account* account) {

	// save our important informtaions
	accountPtr = account;
	filename = "db/transactions_" + std::to_string(account->id) + ".txt";
}

std::ifstream TransactionFileHandler::read()
{
	// returns the file stream
	return std::ifstream(filename);
}

void TransactionFileHandler::writeLn(std::string line)
{
	// buffer for storing the date format
	char buff[21];

	// get the time
	time_t t = time(0);

	// necessary for windows otherwise it won't compile because of a wanrning
	#pragma warning(disable : 4996)

	// format the time string format
	strftime(buff, 21, "%Y-%m-%d %H:%M:%S ", localtime(&t));

	// create our output file
	std::fstream outputFile;

	// we will append to it
	outputFile.open(filename, std::fstream::out | std::fstream::app);

	// stream the timestamp and line
	outputFile << buff << line << std::endl;

	// close the file
	outputFile.close();
}
