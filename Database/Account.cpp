#include "Account.h"


//Default constructor for Account.
Account::Account() {
	accountID = rand();
	this->SSNSet(0);
}
/*
// Login parameterized constructor for Account.
Account::Account(string username, string password)
{
	accountID = rand();
	this->UsernameSet(username);
	this->PasswordSet(password);
}
*/
// Default destructor for Account.
Account::~Account()
{
	transactionIDs.clear();
	carIDs.clear();
}

// Customer Methods
// Sensitive Specifc Methods

// Return a pointer to the list of credit cards on the account.
map<int, CreditCard*>* Account::CardsGet()
{
	return &customer.sensitiveInfo.cards;
}
// Return a bool representing the card's existence, out'ing the card's reference.
bool Account::CardGet(CreditCard *returnCard, int creditCardID)
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
// Create a new card in the account CC list.
bool Account::CardAdd(CreditCard &newCard)
{
	CreditCard *cardRef = new CreditCard; // Out-ed creditcard pointer.
	if (!CardGet(cardRef, newCard.creditCardID)) { // Check if the card doesn't exist already.
		// Set the credit card's variables.
		cardRef->cardNumber = newCard.cardNumber;
		cardRef->creditCardID = newCard.creditCardID;
		cardRef->expiration = newCard.expiration;
		cardRef->holderName = newCard.holderName;
		cardRef->securityCode = newCard.securityCode;
		CardsGet()->insert(make_pair(newCard.creditCardID, cardRef)); // Insert a reference of the new card to the map.
		return true;
	}
	else {
		return false;
	}
}
// Remove the card that holds the given ID.
bool Account::CardRemove(int creditCardID) 
{
	CreditCard* cardRef = new CreditCard; // Out-ed creditcard pointer.
	if (CardGet(cardRef, creditCardID)) { // Check if the card doesn't exist.
		delete cardRef;
		CardsGet()->erase(creditCardID); // Remove the card from the map.
		return true;
	}
	else {
		return false;
	}
}
// Check if the account has the given SSN.
bool Account::SSNCheck(int SSN) 
{
	return (customer.sensitiveInfo.ssn == SSN);
}
// Set the SSN on the given account.
bool Account::SSNSet(int SSN)
{
	if (SSN > 0 && SSN < 1000000000) {
		this->customer.sensitiveInfo.ssn = SSN;
		return true;
	}
	else {
		return false;
	}
}
// Contact Specific Methods

// Set the firstname on the account.
bool Account::FirstNameSet(string firstName)
{
	customer.contactInfo.firstName = firstName;
	return true;
}
// Get the firstname associated with the account.
string Account::FirstNameGet() 
{
	return customer.contactInfo.lastName;
}
// Set the lastname on the account.
bool Account::LastNameSet(string lastName)
{
	customer.contactInfo.lastName = lastName;
	return true;
}
// Get the lastname associated with the account.
string Account::LastNameGet()
{
	return customer.contactInfo.lastName;
}
// Set the phone number on the account.
bool Account::PhoneNumberSet(int newNumber)
{
	if (newNumber > 0) {
		customer.contactInfo.phoneNumber = newNumber;
		return true;
	}
	else {
		return false;
	}
}
// Return the number associated with the account.
int Account::PhoneNumberGet() 
{
	return customer.contactInfo.phoneNumber;
}
// Set the email for the account.
bool Account::EmailSet(string email) 
{
	// Regex match for a valid email address. Where I = Infinity.
	regex emailpattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+"); // 1-I Letters, 0-1 Period, 0-I Letters, 1 @, 1-I (1-I Letters, 1 Dot, 1-I Letters)
	if (regex_match(email, emailpattern)) {
		customer.contactInfo.email = email;
		return true;
	}
	return false;
}
// Get the email associated with the account.
string Account::EmailGet()
{
	return customer.contactInfo.email;
}
// Address Specific Methods

// Set a new city on the account.
bool Account::CitySet(string newCity)
{
	customer.addressInfo.city = newCity;
	return true;
}
// Returns the city on the account.
string Account::CityGet()
{
	return customer.addressInfo.city;
}
// Set a new state on the account, validating the input data.
bool Account::StateSet(string newState)
{
	// List all of the states.
	string states[57] = {"Alabama", "Alaska", "American Samoa", "Arizona", "Arkansas", "California", "Colorado", "Connecticut", "Delaware", "District of Columbia", "Florida", "Georgia", "Guam", "Hawaii", "Idaho", "Illinois", "Indiana", "Iowa", "Kansas", "Kentucky", "Louisiana", "Maine", "Maryland", "Massachusetts", "Michigan", "Minnesota", "Minor Outlying Islands", "Mississippi", "Missouri", "Montana", "Nebraska", "Nevada", "New Hampshire", "New Jersey", "New Mexico", "New York", "North Carolina", "North Dakota", "Northern Mariana Islands", "Ohio", "Oklahoma", "Oregon", "Pennsylvania", "Puerto Rico", "Rhode Island", "South Carolina", "South Dakota", "Tennessee", "Texas", "U.S.Virgin Islands", "Utah", "Vermont", "Virginia", "Washington", "West Virginia", "Wisconsin", "Wyoming"};
	for (string state : states) { // Iterate through the list of states checking for a match.
		if (state == newState) {
			customer.addressInfo.state = newState;
			return true;
		}
	}
	return false; // State match wasn't found, i.e. input is invalid.
}
// Returns the state on the account.
string Account::StateGet()
{
	return customer.addressInfo.state;
}
// Set a new street on the account.
bool Account::StreetSet(string newStreet)
{
	customer.addressInfo.street = newStreet;
	return true;
}
// Returns the street on the account.
string Account::StreetGet()
{
	return customer.addressInfo.street;
}
// Set a new zip on the account.
bool Account::ZipSet(int newZip)
{
	if (newZip > 500 && newZip <= 99950) {
		customer.addressInfo.zip = newZip;
		return true;
	}
	return false;
}
// Returns the zip on the account.
int Account::ZipGet()
{
	return customer.addressInfo.zip;
}

// Set a new username.
bool Account::UsernameSet(string newUsername)
{
	this->username = username;
	return true;
}
// Return the account's username.
string Account::UsernameGet()
{
	return username;
}
// Set a new password.
bool Account::PasswordSet(string newPassword)
{
	smatch pswMatches; // Store matches made during regex checks.

	regex pswRegLet("[\\w]"); // Mathces for letters.
	regex_match(newPassword, pswMatches, pswRegLet); // Match letters.
	if (pswMatches.size() > 5) { // Check if password has at least 5 letters.

		regex pswRegNum("[0-9]"); // Matches for numbers.
		regex_match(newPassword, pswMatches, pswRegNum); // Match numbers.
		if (pswMatches.size() >= 3) { // Check if password has at least 3 digits.

			regex pswRegChr("[\\W]"); // Matches for characters.
			regex_match(newPassword, pswMatches, pswRegChr); // Match character.
			if (pswMatches.size() >= 1) { // Check if password has at least 1 letter.

				this->password = password;
				return true; // Password requirements met.
			}
		}
	}
	return false; // Password requirements not met.
}
// Check given password against the account's stored one.
bool Account::PasswordCheck(string checkPassword)
{
	return password == checkPassword;
}
// Attempt a login on the account, returns -1 on an unsuccessful attempt.
int Account::LoginAttempt(string username, string password) 
{
	// !! Do this
	if (this->username == username && password == password)
	{
		return 1;
		// Logged in
	}
	else
	{
		return -1;
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