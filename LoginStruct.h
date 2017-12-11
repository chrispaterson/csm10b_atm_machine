#pragma once
#include "Account.h"

static const int USERNAME_SIZE = 16;
static const int PIN_SIZE = 4;
static const int MAX_ACCOUNTS = 10;

struct LoginStruct {
	char username[USERNAME_SIZE] = { 0 };
	int pin = 0;
	int num_accounts = 0;
	int accounts[MAX_ACCOUNTS];
};
