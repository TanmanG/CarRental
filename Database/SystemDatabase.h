#pragma once
#include <iostream>
#include <map>
#include "Car.h"
#include "Account.h"
#include "Levenshtein.cpp"

using namespace std;

class SystemDatabase {
private:
	// Hash representing the current state of the database. Adding an object -> add the ID. Removing an object -> subtract the ID.
	int stateHash;
	// Pointer map to all cars in the system.
	map<int, Car*> cars;
	// Pointer map to all accounts in the system.
	map<int, Account*> accounts;
	// Pointer map to all transactions in the system.
	map<int, Transaction*> transactions;
public:
	SystemDatabase();
	~SystemDatabase();

	map<int, Car*>* CarsGet(); // Return the map containing the cars.
	bool CarGet(Car* returnCar, int carID); // Return the car with the given ID.
	bool CarAdd(int carID, string make, string model, float mileage, int year); // Store the passed car to the map, returning if the pass was successful (ID not used).
	bool CarRemove(int carID); // Delete the car with the given ID, returning false if the given ID did not exist.
	
	map<int, Account*>* AccountsGet(); // Return the map containing the accounts.
	bool AccountGet(Account* returnAccount, int accountID); // Return the account with the given ID.
	bool AccountAdd(int accountID); // Create a new account using the given ID. User should calculate the ID using the 'CalculateID' function.
	bool AccountRemove(int accountID); // Remove the account with the given ID, returning false if the account was not found.
	
	map<int, Transaction*>* TransactionsGet(); // Return the map containing the transactions.
	bool TransactionGet(Transaction* returnTransaction, int transactionID); // Return the transaction with the given ID.
	bool TransactionAdd(bool approved, bool archived, int carID, int filerAccountID, int holderAccountID, int transactionID); // Store the passed transaction.
	bool TransactionDelete(int transactionID); // DELETE THE GIVEN TRANSACTION, DO NOT USE.
	bool TransactionSetArchive(int transactionID, bool newStatus); // Set the archival status of the transaction with the given ID.

	int SearchAccount_SSN(int ssn); // Return the account with the given SSN, returning -1 on a fail.
	int SearchTransaction_CAR(int carID); // Search for a non-archived transaction involving a car with the given ID, returning -1 on a fail.
	vector<int>* SearchAccount_FNAME(string firstname, float tolerance); // Return a list of accountIDs of all accounts with firstnames within the given percentage difference, returning -1 on a fail.
	vector<int>* SearchAccount_LNAME(string lastname, float tolerance); // Return a list of accountIDs of all accounts with lastnames within the given percentage difference, returning -1 on a fail.
};