#pragma once
#include <string>

struct Address {
	// Streetname of the customer.
	std::string street = "8653 NW 120th St";
	// City name of the customer.
	std::string city = "Potwin";
	// State name of the customer.
	std::string state = "Kansas";
	// ZIP code of the customer.
	int zip = 67123;

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