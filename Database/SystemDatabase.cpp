// Database.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "SystemDatabase.h"

int main()
{
    cout << LevenshteinDistance("he", "hello");
    //test.CardAdd();
}

// Default constructor for SystemDatabase.
SystemDatabase::SystemDatabase() 
{
    stateHash = 0;
}
// Default destructor for SystemDatabase.
SystemDatabase::~SystemDatabase() 
{
    // Dealloc each element individually.
    for (const auto& car : cars) { // Iterate through each car.
        delete car.second; // Delete the car struct.
    } cars.clear(); // Clear the car map of pointers.

    for (const auto& account : accounts) { // Iterate through each account.
        delete account.second; // Call the account deconstructor.
    } accounts.clear(); // Clear the account map of pointers.

    for (const auto& transaction : transactions) { // Iterate through each transaction.
        delete transaction.second; // Delete the transaction struct.
    } transactions.clear(); // Clear the transaction map of pointers.
}

// Return the map containing the cars.
map<int, Car*>* SystemDatabase::CarsGet()
{
    return &cars;
}
// Return the car with the given ID.
bool SystemDatabase::CarGet(Car* returnCar, int carID)
{
    auto it = CarsGet()->find(carID); // Search for the card in the cards map.
    if (it != CarsGet()->end()) { // Check if the card is present in the map.
        returnCar = it->second; // Set the return pointer to the found card.
        return true;
    }
    else {
        return false;
    }
}
// Store the passed car to the map, returning if the pass was successful (ID not used).
bool SystemDatabase::CarAdd(int carID, string make, string model, float mileage, int year)
{
    Car* carRef = new Car(); // Declare the car to be added to the list.
    if (!CarGet(carRef, carID)) { // Check if a car with the given ID already exists.
        carRef->carID = carID;
        carRef->make = make;
        carRef->mileage = mileage;
        carRef->model = model;
        carRef->year = year;
        stateHash += carID; // Increase the stateHash.
        cars.insert(make_pair(carID, carRef));
        return true;
    }
    else {
        return false;
    }
}
// Delete the car with the given ID, returning false if the given ID did not exist.
bool SystemDatabase::CarRemove(int carID)
{
    Car* carRef = new Car; // Out-ed creditcard pointer.
    if (CarGet(carRef, carID)) { // Check if the car doesn't exist.
        stateHash -= carID; // Lower the stateHash.
        delete carRef; // Delete the car struct.
        CarsGet()->erase(carID); // Remove the car from the map.
        return true;
    }
    else {
        return false;
    }
}

// Return the map containing the accounts.
map<int, Account*>* SystemDatabase::AccountsGet()
{
    return &accounts;
}
// Return the account with the given ID.
bool SystemDatabase::AccountGet(Account* returnAccount, int accountID)
{
    auto it = AccountsGet()->find(accountID); // Search for the card in the cards map.
    if (it != AccountsGet()->end()) { // Check if the card is present in the map.
        returnAccount = it->second; // Set the return pointer to the found card.
        return true;
    }
    else {
        return false;
    }
}
// Store the passed account to the map, returning if the pass was successful (SSN was unused).
bool SystemDatabase::AccountAdd(int accountID)
{
    Account* accountRef = new Account(); // Declare the account to be added to the list.
    if (!AccountGet(accountRef, accountID)) { // Check if an account with the given ID already exists.
        accountRef->accountID = accountID; // Set account parameters.
        stateHash += accountID; // Increase the stateHash.
        accounts.insert(make_pair(accountRef->accountID, accountRef)); // Insert the account into the map.
        return true;
    }
    else {
        return false;
    }
}
// Remove the account with the given ID, returning false if the account was not found.
bool SystemDatabase::AccountRemove(int accountID)
{
    Account* accountRef = new Account(); // Declare the account to be added to the list.
    if (AccountGet(accountRef, accountID)) // Check if the object exists within the account list.
    {
        stateHash -= accountID; // Lower the stateHash.
        delete accountRef; // Call the account deconstructor.
        AccountsGet()->erase(accountID); // Erase the entry in the list.
        return true;
    }
    return false;
}

// Return the map containing the transactions.
map<int, Transaction*>* SystemDatabase::TransactionsGet()
{
    return &transactions;
}
// Return the transaction with the given ID.
bool SystemDatabase::TransactionGet(Transaction* returnTransaction, int transactionID)
{
    auto it = TransactionsGet()->find(transactionID); // Search for the card in the cards map.
    if (it != TransactionsGet()->end()) { // Check if the card is present in the map.
        returnTransaction = it->second; // Set the return pointer to the found card.
        return true;
    }
    else {
        return false;
    }
}
// Store the passed transaction.
bool SystemDatabase::TransactionAdd(bool approved, bool archived, int carID, int filerAccountID, int holderAccountID, int transactionID)
{
    Transaction* transactionRef = new Transaction(); // Declare the account to be added to the list.
    if (!TransactionGet(transactionRef, transactionID)) { // Check if an account with the given ID already exists.
        transactionRef->transactionID = transactionID; // Set account parameters.
        stateHash += transactionID;
        transactions.insert(make_pair(transactionID, transactionRef)); // Insert the account into the map.
        return true;
    }
    return false;
}
// Delete the transaction with the given ID. Avoid using this for the sake of recordkeeping.
bool SystemDatabase::TransactionDelete(int transactionID)
{
    auto it = TransactionsGet()->find(transactionID); // Get an iterator to the element with the given transactionID.
    if (it != TransactionsGet()->end()) { // Check the iterator to see if the transaction exists.
        stateHash -= transactionID; // Lower the stateHash.
        delete it->second; // Delete the permissions struct.
        TransactionsGet()->erase(transactionID); // Remove the map entry for the transaction.
        return true;
    }
    else {
        return false;
    }
}
// Set the archival status of the transaction with the given ID.
bool SystemDatabase::TransactionSetArchive(int transactionID, bool newStatus)
{
    auto it = TransactionsGet()->find(transactionID); // Get an iterator to the element with the given transactionID.
    if (it != TransactionsGet()->end()) { // Check the iterator to see if the transaction exists.
        it->second->archived = newStatus; // Update the bool for archivality.
        return true;
    }
    else {
        return false;
    }
}

// Search Functions

// Return the account with the given SSN.
int SystemDatabase::SearchAccount_SSN(int ssn)
{
    for (const auto& account : accounts) { // Iterate through each account.
        if (account.second->SSNCheck(ssn)) { // Check if the given SSN matches the current account.
            return account.second->accountID;
        }
    }
    return -1;
}
// Search for a non-archived transaction involving a car with the given ID.
int SystemDatabase::SearchTransaction_CAR(int carID)
{
    for (const auto& transaction : transactions) { // Iterate through each transaction.
        if (transaction.second->carID == carID) { // Check if the given SSN matches the current account.
            return transaction.second->transactionID;
        }
    }
    return -1;
}
/*
// Return a list of accountIDs of all accounts with firstnames within the given percentage difference.
vector<int>* SearchAccount_FNAME(string firstname, float tolerance)
{
    // IMPLEMENT LEVENSHTEIN
    
}
vector<int>* SearchAccount_LNAME(string lastname, float tolerance); // Return a list of accountIDs of all accounts with lastnames within the given percentage difference.
*/