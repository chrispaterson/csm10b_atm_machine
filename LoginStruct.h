#pragma once


struct LoginStruct {

	// some constants for this struct
	static const int USERNAME_SIZE = 16;
	static const int PIN_SIZE = 4;
	static const int MAX_ACCOUNTS = 10;

	// self explanitory 
	char username[USERNAME_SIZE] = { 0 };
	int pin = 0;

	// keep track of how many accounts
	int num_accounts = 0;

	// int account numbers
	int accounts[MAX_ACCOUNTS];
};
