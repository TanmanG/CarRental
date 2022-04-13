#pragma once
#include <String>

struct Contact {
	// First name of the customer.
	std::string firstName = "None";
	// Last name of the customer.
	std::string lastName = "None";
	// Email of the customer.
	std::string email = "None";
	// Phone number of the customer.
	int phoneNumber = -1;

	// Serialization
	template <typename Archive>
	void serialize(Archive& ar, const unsigned int version)
	{
		ar& firstName;
		ar& lastName;
		ar& email;
		ar& phoneNumber;
	}
};