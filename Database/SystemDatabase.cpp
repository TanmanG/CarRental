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
}

/*
// Store the passed car to the map, returning if the pass was successful (ID not used).
bool SystemDatabase::AddCar(Car* car) 
{

} 
// Delete the car with the given ID, returning false if the given ID did not exist.
bool SystemDatabase::RemoveCar(int carID) 
{

} 
// Store the passed account to the map, returning if the pass was successful (SSN was unused).
bool SystemDatabase::AddAccount(Account* account) 
{

} 

// Remove the account with the given ID, returning false if the account was not found.
bool SystemDatabase::RemoveAccount(int accountID)
{

} 
*/

// Search Functions
// Search for an account given the ID.
/*
Account* SystemDatabase::SearchAccountID(int accountID)
{

}
// Search for account using SSN, returning the accountID.
int SystemDatabase::SearchAccountSSN(int social)
{

} 
// Search for accounts using first name, returning accountIDs.
vector<int>* SystemDatabase::SearchAccountFName(string firstName)
{
    for (auto it = accounts.cbegin(); it != accounts.cend(); it++) {
        if (*it->second.)
    }
} 
// Search for accounts using last name, returning accountIDs.
vector<int>* SystemDatabase::SearchAccountLName(string lastName) 
{

}
*/