#pragma once
struct Transaction
{
	// Unique ID of the transaction.
	int transactionID = -1;
	// Unique ID of the car involved in the transaction.
	int carID = -1;
	// Unique ID of the new holder of the car.
	int holderAccountID = -1;
	// Unique ID of the creator of the transaction.
	int filerAccountID = -1;
	// Boolean tracking whether the transaction is active (i.e. the involved car is currently being rented or not).
	bool archived = false;

	// Serialization
	template <typename Archive>
	void serialize(Archive& ar, const unsigned int version)
	{
		ar& transactionID;
		ar& carID;
		ar& holderAccountID;
		ar& filerAccountID;
		ar& archived;
	}
};

