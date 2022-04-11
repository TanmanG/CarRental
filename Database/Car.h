#pragma once
#include <string>

struct Car
{
	// Unique ID of the car.
	int carID;
	// ID associated with transaction involving the car.
	int transactionID;
	// Make of the car (i.e. manufacturer).
	std::string make;
	// Model of the car.
	std::string model;
	// Model year of the car.
	int year;
	// Mileage of the car.
	float mileage;

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