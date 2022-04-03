#pragma once
#include <iostream>
#include <map>
#include "Car.h"
#include "Account.h"

using namespace std;

class SystemDatabase {
private:
	map<int, Car*> cars;
	map<int, Account*> accounts;
	map<int, Transaction*> transactions;
public:
	SystemDatabase();
	~SystemDatabase();

	map<int, Car*>* CarsGet(); // Return the map containing the cars.
	bool CarGet(Car* returnCar, int carID); // Return the car with the given ID.
	bool CarAdd(Car& newCar); // Store the passed car to the map, returning if the pass was successful (ID not used).
	bool CarRemove(int carID); // Delete the car with the given ID, returning false if the given ID did not exist.
	
	map<int, Account*>* AccountsGet(); // Return the map containing the accounts.
	bool AccountGet(Account* returnAccount, int accountID); // Return the account with the given ID.
	bool AccountAdd(Account& newAccount); // Store the passed account to the map, returning if the pass was successful (SSN was unused).
	bool AccountRemove(int accountID); // Remove the account with the given ID, returning false if the account was not found.
	
	map<int, Transaction*>* TransactionsGet(); // Return the map containing the transactions.
	bool TransactionGet(Transaction* returnTransaction, int transactionID); // Return the transaction with the given ID.
	bool TransactionAdd(Transaction& newTransaction); // Store the passed transaction.
	bool TransactionDelete(int transactionID); // DELETE THE GIVEN TRANSACTION, DO NOT USE.
	bool TransactionEnable(int transactionID); // Enable the given transaction.
	bool TransactionDisable(int transactionID); // Disable the given transaction.

	// Search Functions
	Account* SearchAccountID(int accountID); // Search for an account given the ID.
	int SearchAccountSSN(int ssn); // Search for account using SSN, returning the accountID, or -1 on a failed search.
	vector<int>* SearchAccountFName(string firstName); // Search for accounts using first name, returning accountIDs. Destroy after use.
	vector<int>* SearchAccountLName(string lastName); // Search for accounts using last name, returning accountIDs. Destroy after use.
};