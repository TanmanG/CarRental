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
};