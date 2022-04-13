#pragma once
#include <string>

struct CreditCard {
	// Unique ID for the card.
	int creditCardID = rand();
	// Front 16 digit code of the card.
	int cardNumber = -1;
	// Back 3 digits of the card.
	int securityCode = -1;
	// Expiration MM/YY of the card.
	std::string expiration = "None";
	// Cardholder name.
	std::string holderName = "None";

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