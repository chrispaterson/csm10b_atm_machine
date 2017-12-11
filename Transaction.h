#pragma once
#include <string>

const static int LABEL_SIZE = 20;

struct Transaction
{
	int id;
	double amount;
	char label[LABEL_SIZE] = { 0 };

};

Transaction operator+(Transaction const& lhs, Transaction const& rhs) {

	Transaction retr;

	std::string label1(lhs.label);
	label1 = label1.substr(0, LABEL_SIZE / 2 - 4) + "...";
	std::string label2(rhs.label);
	label2 = label2.substr(0, LABEL_SIZE / 2 - 4) + "...";

	std::string new_label = label1 + "+" + label2;
	strcpy(retr.label, new_label.c_str());

	retr.amount = lhs.amount + rhs.amount;

	return retr;

}