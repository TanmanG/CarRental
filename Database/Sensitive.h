#pragma once
#include "CreditCard.h"
#include <boost/serialization/string.hpp>
#include <boost/serialization/map.hpp>

struct Sensitive {
	// Social Security Number of the accountholder (!! ENCRPYT)
	int ssn = -1;
	// Map of the unique ID and pointers to the account's creditcards.
	std::map<int, CreditCard*> cards;

	// Serialization
	template <typename Archive>
	void serialize(Archive& ar, const unsigned int version)
	{
		ar& ssn;
		ar& cards;
	}
};