#pragma once
#include <string>
#include <map>
#include "CreditCard.h"

struct Sensitive {
	// Social Security Number of the accountholder (!! ENCRPYT)
	int ssn = 0;
	// Map of the unique ID and pointers to the account's creditcards.
	std::map<int, CreditCard*> cards;
};