#pragma once
#include <iostream>
#include <map>
#include "Car.h"
#include "Account.h"

using namespace std;

class SystemDatabase {
private:
	map<int, Car> cars;
	map<int, Account> accounts;
	map<int, Transaction> transactions;
public:
	SystemDatabase();
	~SystemDatabase();

	bool AddCar(Car* car); // Store the passed car to the map, returning if the pass was successful (ID not used).
	bool RemoveCar(int carID); // Delete the car with the given ID, returning false if the given ID did not exist.
	bool AddAccount(Account* account); // Store the passed account to the map, returning if the pass was successful (SSN was unused).
	bool RemoveAccount(int accountID); // Remove the account with the given ID, returning false if the account was not found.

	// Search Functions
	Account* SearchAccountID(int accountID); // Search for an account given the ID.
	int SearchAccountSSN(int social); // Search for account using SSN, returning the accountID, or -1 on a failed search.
	vector<int>* SearchAccountFName(string firstName); // Search for accounts using first name, returning accountIDs.
	vector<int>* SearchAccountLName(string lastName); // Search for accounts using last name, returning accountIDs.
};