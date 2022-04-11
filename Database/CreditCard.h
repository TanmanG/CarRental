#pragma once
#include <string>

struct CreditCard {
	// Unique ID for the card.
	int creditCardID = rand();
	// Front 16 digit code of the card.
	int cardNumber = -1;
	// Back 3 digits of the card.
	int securityCode = 0;
	// Expiration MM/YY of the card.
	std::string expiration = "01/1999";
	// Cardholder name.
	std::string holderName = "Bobby Boy";

	// Serialization
	template <typename Archive>
	void serialize(Archive& ar, const unsigned int version)
	{
		ar& creditCardID;
		ar& cardNumber;
		ar& securityCode;
		ar& expiration;
		ar& holderName;
	}
};