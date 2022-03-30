#pragma once
#include <string>

struct CreditCard {
	int creditCardID;
	int cardNumber;
	int securityCode;
	std::string expiration;
	std::string holderName;
};