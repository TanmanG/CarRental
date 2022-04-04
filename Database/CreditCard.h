#pragma once
#include <string>

struct CreditCard {
	// Unique ID for the card.
	int creditCardID;
	// Front 16 digit code of the card.
	int cardNumber;
	// Back 3 digits of the card.
	int securityCode;
	// Expiration MM/YY of the card.
	std::string expiration;
	// Cardholder name.
	std::string holderName;
};