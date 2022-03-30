#pragma once
#include <string>

struct CreditCard {
	int cardNumber;
	int securityCode;
	std::string expiration;
	std::string holderName;
};