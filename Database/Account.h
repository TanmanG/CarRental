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

	// Customer Specific Methods
	//Sensitive sensitiveInfo;
	//Contact contactInfo;
	//Address addressInfo;
	// Sensitive Specifc Methods
	vector<CreditCard>* CardsGet(); // Return a pointer to the list of credit cards on the account.
	CreditCard* CardGet(int creditCardID); // Return a pointer to a credit card given a unique ID.
	bool CardAdd(CreditCard* newCard); // Create a new card in the account CC list.
	bool CardRemove(int creditCardID); // Remove the card that holds the given ID.
	bool SSNCheck(int SSN); // Check if the account has the given SSN.
	bool SSNSet(int SSN); // Set the SSN on the given account.

	// Contact Specific Methods
	bool FirstNameSet(string firstName); // Set the firstname on the account.
	string FirstNameGet(); // Get the firstname associated with the account.
	bool LastNameSet(string lastName); // Set the lastname on the account.
	string LastNameGet(); // Get the lastname associated with the account.

	// Account Specific Methods
	void UsernameSet(string username); // Set a new username.
	void PasswordSet(string password); // Set a new password.
	int LoginAttempt(string username, string password); // Attempt a login on the account, returns -1 on a fail.
	bool CarAdd(int carID); // Track a new car to this account, if so, return true.
	bool CarGet(int carID); // Check if a car exists, if so, return true.
	bool TransactionAdd(int transactionID); // Track a new transaction to this account, if so, return true.
	bool TransactionGet(int transactionID); // Check if a transaction exists, if so, return true.
};