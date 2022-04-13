#pragma once
#include <string>

struct Address {
	// Streetname of the customer.
	std::string street = "None";
	// City name of the customer.
	std::string city = "None";
	// State name of the customer.
	std::string state = "None";
	// ZIP code of the customer.
	int zip = -1;

	// Serialization
	template <typename Archive>
	void serialize(Archive& ar, const unsigned int version)
	{
		ar& street;
		ar& city;
		ar& state;
		ar& zip;
	}
};