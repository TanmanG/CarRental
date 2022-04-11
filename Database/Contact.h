#pragma once
#include <String>

struct Contact {
	// First name of the customer.
	std::string firstName = "Bobbi";
	// Last name of the customer.
	std::string lastName = "Boy";
	// Email of the customer.
	std::string email = "bobbiboy6@yahoo.com";
	// Phone number of the customer.
	int phoneNumber = 1234567890;

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