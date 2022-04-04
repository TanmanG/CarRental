#pragma once
struct Transaction
{
	// Unique ID of the transaction.
	int transactionID;
	// Unique ID of the car involved in the transaction.
	int carID;
	// Unique ID of the new holder of the car.
	int holderAccountID;
	// Unique ID of the creator of the transaction.
	int filerAccountID;
	// Boolean tracking whether the transaction is active (i.e. the involved car is currently being rented or not).
	bool archived;
};

