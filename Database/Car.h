#pragma once
#include <string>

struct Car
{
	// Unique ID of the car.
	int carID = -1;
	// ID associated with transaction involving the car.
	int transactionID = -1;
	// Make of the car (i.e. manufacturer).
	std::string make = "None";
	// Model of the car.
	std::string model = "None";
	// Model year of the car.
	int year = -1;
	// Mileage of the car.
	float mileage = -1;

	// Serialization
	template <typename Archive>
	void serialize(Archive& ar, const unsigned int version)
	{
		ar& carID;
		ar& transactionID;
		ar& make;
		ar& model;
		ar& year;
		ar& mileage;
	}
};