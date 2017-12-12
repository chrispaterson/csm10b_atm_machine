#pragma once

// enum of types of accounts
enum Account_Type {Checking, Savings, CD};

// create our struct
struct Account
{
	int id;
	Account_Type type;
	double balance;

	// operator overload for adding two accounts together
	inline Account& operator+=(const Account& rhs) {
		this->balance += rhs.balance;
		return *this;
	}
};
