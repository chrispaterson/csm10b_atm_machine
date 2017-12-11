#pragma once

enum Account_Type {Checking, Savings, CD};

struct Account
{
	int id;
	Account_Type type;
	double balance;
};

