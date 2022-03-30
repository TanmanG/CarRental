#pragma once
#include <string>
#include <vector>
#include "Customer.h"
#include "Permissions.h"
#include "Transaction.h"
#include "Car.h"
using namespace std;

class Account
{
private:
	// Start of Variable Declaration
	string username;
	string password;
	Customer customer;
	// End of Variable Delaration
public:
	// Start of Variable Declaration
	int accountID;
	Permissions permissions;
	vector<int> transactionIDs;
	vector<int> carIDs;
	// End of Variable Declaration

	Account(string username, string password);
	~Account();

	void UsernameSet(string username); // Set a new username.
	void PasswordSet(string password); // Set a new password.
	int LoginAttempt(string username, string password); // Attempt a login on the account, returns -1 on a fail.
	bool CarAdd(int carID); // Track a new car to this account, if so, return true.
	bool CarGet(int carID); // Check if a car exists, if so, return true.
	bool TransactionAdd(int transactionID); // Track a new transaction to this account, if so, return true.
	bool TransactionGet(int transactionID); // Check if a transaction exists, if so, return true.
};