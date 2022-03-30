#include "Account.h"
#include <algorithm>

// Default constructor for Account.
Account::Account(string username, string password)
{
	this->UsernameSet(username);
	this->PasswordSet(password);
}
// Default destructor for Account.
Account::~Account()
{
	transactionIDs.clear();
	carIDs.clear();
}

// Set a new username.
void Account::UsernameSet(string username)
{
	this->username = username;
}
// Set a new password.
void Account::PasswordSet(string password)
{
	this->password = password;
}
// Attempt a login on the account, returns -1 on an unsuccessful attempt.
int Account::LoginAttempt(string username, string password) 
{
	if (this->username == username && password == password)
	{
		// Logged in
	}
	else
	{
		// Login failed
	}
}
// Track a new car to this account, if so, return true.
bool Account::CarAdd(int carID)
{
	if (!CarGet(carID)) {
		carIDs.push_back(carID);
		return true; // Car ID was successfully tracked.
	}
	else {
		return false; // Car ID is already present.
	}
}
// Check if a car is bound to this account, if so, return true.
bool Account::CarGet(int carID) {
	return find(carIDs.begin(), carIDs.end(), carID) != carIDs.end();
}
// Track a new transaction to this account, if so, return true.
bool Account::TransactionAdd(int transactionID)
{
	if (!TransactionGet(transactionID)) {
		transactionIDs.push_back(transactionID);
		return true; // Transaction ID was successfully tracked.
	}
	else {
		return false; // Transaction ID is already present.
	}
}
// Check if a transaction is bound to this account, if so, return true.
bool Account::TransactionGet(int transactionID) {
	return find(transactionIDs.begin(), transactionIDs.end(), transactionID) != transactionIDs.end();
}