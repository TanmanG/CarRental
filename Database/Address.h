#pragma once
#include <string>

struct Address {
	// Streetname of the customer.
	std::string street;
	// City name of the customer.
	std::string city;
	// State name of the customer.
	std::string state;
	// ZIP code of the customer.
	int zip;
};