#pragma once
struct Transaction
{
	int transactionID;
	int carID;
	int holderAccountID;
	int filerAccountID;
	bool approved;
	bool archived;
};

