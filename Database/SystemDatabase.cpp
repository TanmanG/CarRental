// Database.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "SystemDatabase.h"

int main()
{
    cout << "Hello World!\n";
    Account test;
    cout << test.EmailSet("tgood2001@hotmail.com");
    cout << test.EmailGet();
    //test.CardAdd();
}

// Default constructor for SystemDatabase.
SystemDatabase::SystemDatabase() 
{

}
// Default destructor for SystemDatabase.
SystemDatabase::~SystemDatabase() 
{
    cars.clear();
    accounts.clear();
    transactions.clear();
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
bool SystemDatabase::CarAdd(Car& newCar)
{
    // !! IMPLEMENT CHECK
    Car* passCar = new Car();
    passCar->carID = newCar.carID;
    passCar->make = newCar.make;
    passCar->mileage = newCar.mileage;
    passCar->model = newCar.model;
    passCar->year = newCar.year;
    cars.insert(make_pair(passCar->carID, passCar));
}
// Delete the car with the given ID, returning false if the given ID did not exist.
bool SystemDatabase::CarRemove(int carID)
{
    Car* carRef = new Car; // Out-ed creditcard pointer.
    if (CarGet(carRef, carID)) { // Check if the car doesn't exist.
        delete carRef;
        CarsGet()->erase(carID); // Remove the car from the map.
        return true;
    }
    else {
        return false;
    }
}

// Return the map containing the cars.
map<int, Account*>* SystemDatabase::AccountsGet()
{
    return &accounts;
}
// Return the account with the given ID.
bool SystemDatabase::AccountGet(Account* returnAccount, int carID)
{
    auto it = AccountsGet()->find(carID); // Search for the card in the cards map.
    if (it != AccountsGet()->end()) { // Check if the card is present in the map.
        returnAccount = it->second; // Set the return pointer to the found card.
        return true;
    }
    else {
        return false;
    }
}
// Store the passed account to the map, returning if the pass was successful (SSN was unused).
bool AccountAdd(Account& account)
{
    // IMPLEMENT CHECK AND PASS PARAMETERS INSTEAD OF AN OBJECT!
}
bool AccountRemove(int accountID); // Remove the account with the given ID, returning false if the account was not found.

bool TransactionGet(CreditCard* returnCard, int carID); // Return the transaction with the given ID.
bool TransactionAdd(Transaction& transaction); // Store the passed transaction.
bool TransactionDelete(int transactionID); // DELETE THE GIVEN TRANSACTION, DO NOT USE.
bool TransactionEnable(int transactionID); // Enable the given transaction.
bool TransactionDisable(int transactionID); // Disable the given transaction.

// Search Functions
Account* SystemDatabase::SearchAccountID(int accountID); // Search for an account given the ID.
int SystemDatabase::SearchAccountSSN(int ssn); // Search for account using SSN, returning the accountID, or -1 on a failed search.
vector<int>* SystemDatabase::SearchAccountFName(string firstName); // Search for accounts using first name, returning accountIDs. Destroy after use.
vector<int>* SystemDatabase::SearchAccountLName(string lastName); // Search for accounts using last name, returning accountIDs. Destroy after use.