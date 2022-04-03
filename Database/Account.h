#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <regex>
#include "Customer.h"
#include "Permissions.h"
#include "Transaction.h"
#include "Car.h"
using namespace std;

class Account
{
private:
	// Start of Variable Declaration

	// Username to the account.
	string username;
	// Password to the account.
	string password;
	// Struct containing all the personal info on the accountowner.
	Customer customer;

	// End of Variable Delaration
public:
	// Start of Variable Declaration

	// Unique ID associated with the account.
	int accountID;
	// Struct containing perimissions of the account.
	Permissions permissions;
	// Vector containing a list of the associated transactions.
	vector<int> transactionIDs;
	// Vector containing a list of the associated cars.
	vector<int> carIDs;

	// End of Variable Declaration

	Account();
	Account(string username, string password);
	~Account();

	// Customer Methods
	// Sensitive Specifc Methods
	map<int, CreditCard*>* CardsGet(); // Return a pointer to the list of credit cards on the account.
	bool CardGet(CreditCard* returnCard, int creditCardID); // Return a pointer to a credit card given a unique ID.
	bool CardAdd(CreditCard& newCard); // Create a new card in the account CC list.
	bool CardRemove(int creditCardID); // Remove the card that holds the given ID.
	bool SSNCheck(int SSN); // Check if the account has the given SSN.
	bool SSNSet(int SSN); // Set the SSN on the given account.

	// Contact Specific Methods
	bool FirstNameSet(string firstName); // Set the firstname on the account.
	string FirstNameGet(); // Get the firstname associated with the account.
	bool LastNameSet(string lastName); // Set the lastname on the account.
	string LastNameGet(); // Get the lastname associated with the account.
	bool PhoneNumberSet(int newNumber); // Set the phone number on the account.
	int PhoneNumberGet(); // Return the number associated with the account.
	bool EmailSet(string email); // Set the email for the account.
	string EmailGet(); // Get the email associated with the account.

	// Address Specific Methods
	bool CitySet(string newCity); // Set a new city on the account.
	string CityGet(); // Returns the city on the account.
	bool StateSet(string newState); // Set a new state on the account.
	string StateGet(); // Returns the state on the account.
	bool StreetSet(string newStreet); // Set a new street on the account.
	string StreetGet(); // Returns the street on the account.
	bool ZipSet(int newZip); // Set a new zip on the account.
	int ZipGet(); // Returns the zip on the account.

	// Account Methods
	bool UsernameSet(string newUsername); // Set a new username.
	string UsernameGet(); // Return the account's username.
	bool PasswordSet(string newPassword); // Set a new password.
	bool PasswordCheck(string checkPassword); // Check given password against the account's stored one.
	int LoginAttempt(string username, string password); // Attempt a login on the account, returns -1 on a fail.
	bool CarAdd(int carID); // Track a new car to this account, if so, return true.
	bool CarGet(int carID); // Check if a car exists, if so, return true.
	bool TransactionAdd(int transactionID); // Track a new transaction to this account, if so, return true.
	bool TransactionGet(int transactionID); // Check if a transaction exists, if so, return true.
};