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

// Customer Methods
	// Sensitive Specifc Methods
map<int, CreditCard>* Account::CardsGet() // Return a pointer to the list of credit cards on the account.
{
	return &this->customer.sensitiveInfo.cards;
}
bool Account::CardGet(CreditCard &returnCard, int creditCardID) // Return a bool representing the card's existence, out'ing the card's reference.
{
	auto it = CardsGet()->find(creditCardID); // Search for the card in the cards map.
	if (it != CardsGet()->end()) { // Check if the card is present in the map.
		returnCard = it->second; // Set the return pointer to the found card.
		return true;
	}
	else {
		return false;
	}
}
bool Account::CardAdd(CreditCard* newCard) // Create a new card in the account CC list.
{
	// !! IMPLEMENT THIS
	CreditCard _; // Unused, only for parameter fullfillment.
	if (!CardGet(_, newCard->creditCardID)) { // Check if the card doesn't exist already.
		//CreditCard cc = new CreditCard();
		//CardsGet()->insert()
	}
}
bool Account::CardRemove(int creditCardID) // Remove the card that holds the given ID.
{

}
bool Account::SSNCheck(int SSN) // Check if the account has the given SSN.
{

}
bool Account::SSNSet(int SSN) // Set the SSN on the given account.
{
	
}

// Contact Specific Methods
bool Account::FirstNameSet(string firstName); // Set the firstname on the account.
string Account::FirstNameGet(); // Get the firstname associated with the account.
bool Account::LastNameSet(string lastName); // Set the lastname on the account.
string Account::LastNameGet(); // Get the lastname associated with the account.
bool Account::PhoneNumberSet(int newNumber); // Set the phone number on the account.
int Account::PhoneNumberGet(); // Return the number associated with the account.
bool Account::EmailSet(string email); // Set the email for the account.
string Account::EmailGet(); // Get the email associated with the account.

// Address Specific Methods
bool CitySet(string newCity); // Set a new city on the account.
string CityGet(); // Returns the city on the account.
bool CountrySet(string newCountry); // Set a new country on the account.
string CountryGet(); // Returns the country on the account.
bool StateSet(string newState); // Set a new state on the account.
string StateGet(); // Returns the state on the account.
bool StreetSet(string newStreet); // Set a new street on the account.
string StreetGet(); // Returns the street on the account.
bool ZipSet(int newZip); // Set a new zip on the account.
int ZipGet(); // Returns the zip on the account.

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