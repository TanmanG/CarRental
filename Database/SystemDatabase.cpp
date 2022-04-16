// Database.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "SystemDatabase.h"

int main()
{
    // !! TODO: Fix lastname not getting read in this example???
    // !! For some reason the DBRead() function isn't working. It appears to write fine but I can't find a way to write an object again. Maybe just make a static read thing???
    SystemDatabase* test = new SystemDatabase();
    test->AccountAdd(52525);
    
    {
        tuple<bool, Account*> acc1Result = test->AccountGet(52525);
        if (get<0>(acc1Result)) {
            get<1>(acc1Result)->FirstNameSet("John");
            test->StateHashUpdate("John");
            get<1>(acc1Result)->LastNameSet("Orange");
            test->StateHashUpdate("Orange");
        }
        cout << get<1>(test->AccountGet(test->SearchAccount_FNAME("John", 1).front()))->LastNameGet();
    }

    test->DBWrite();

    {
        tuple<bool, Account*> acc1Result = test->AccountGet(52525);
        if (get<0>(acc1Result)) {
            get<1>(acc1Result)->FirstNameSet("John");
            test->StateHashUpdate("John");
            get<1>(acc1Result)->LastNameSet("Brown");
            test->StateHashUpdate("Brown");
        }
        cout << get<1>(test->AccountGet(test->SearchAccount_FNAME("John", 1).front()))->LastNameGet();
    }

    test->DBRead(test);
    cout << get<1>(test->AccountGet(test->SearchAccount_FNAME("John", 1).front()))->LastNameGet();

    /* Example Usage.
    SystemDatabase test;
    
    // Fuzzy search.
    vector<int> newVec = test.SearchAccount_LNAME("Steve", 0.5);
    for (int i : newVec) {
        tuple<bool, Account*> results = test.AccountGet(i);
        cout << get<1>(results)->FirstNameGet() << endl;
    }
    */
}

// Class Implementations
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

// Return the current hash state of the database.
int SystemDatabase::StateHashGet()
{
    return stateHash;
}

// Return the map containing the cars.
map<int, Car*>* SystemDatabase::CarsGet()
{
    return &cars;
}
// Return the car with the given ID.
tuple<bool, Car*> SystemDatabase::CarGet(int carID)
{
    auto it = CarsGet()->find(carID); // Search for the card in the cards map.
    if (it != CarsGet()->end()) { // Check if the card is present in the map.
        return make_tuple(true, it->second);
    }
    else {
        return make_tuple(false, nullptr);
    }
}
// Store the passed car to the map, returning if the pass was successful (ID not used).
bool SystemDatabase::CarAdd(int carID, string make, string model, float mileage, int year)
{
    tuple<bool, Car*> carResult = CarGet(carID); // Declare the car to be added to the list.
    if (!get<0>(carResult)) { // Check if a car with the given ID already exists.
        get<1>(carResult)->carID = carID;
        get<1>(carResult)->make = make;
        get<1>(carResult)->mileage = mileage;
        get<1>(carResult)->model = model;
        get<1>(carResult)->year = year;
        StateHashUpdate(to_string(carID)); // Increase the stateHash.
        cars.insert(make_pair(carID, get<1>(carResult)));
        return true;
    }
    else {
        return false;
    }
}
// Delete the car with the given ID, returning false if the given ID did not exist.
bool SystemDatabase::CarRemove(int carID)
{
    tuple<bool, Car*> carResult = CarGet(carID); // Out-ed creditcard pointer.
    if (get<0>(carResult)) { // Check if the car doesn't exist.
        StateHashUpdate(to_string(carID));; // Lower the stateHash.
        delete get<1>(carResult); // Delete the car struct.
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
tuple<bool, Account*> SystemDatabase::AccountGet(int accountID)
{
    auto it = AccountsGet()->find(accountID); // Search for the card in the cards map.
    if (it != AccountsGet()->end()) { // Check if the card is present in the map.
        return make_tuple(true, it->second);
    }
    else {
        return make_tuple(false, nullptr);
    }
}
// Store the passed account to the map, returning if the pass was successful (SSN was unused).
bool SystemDatabase::AccountAdd(int accountID)
{
    tuple<bool, Account*> accountResult = AccountGet(accountID); // Check if an account with the given ID exists.
    if (!get<0>(accountResult)) { // Check if an account with the given ID already exists.
        Account* newAccount = new Account(accountID); // Create a new account with the given ID.
        StateHashUpdate(to_string(accountID)); // Increase the stateHash.
        accounts.insert(make_pair(accountID, newAccount)); // Insert the account into the map.
        return true;
    }
    else {
        return false;
    }
}
// Remove the account with the given ID, returning false if the account was not found.
bool SystemDatabase::AccountRemove(int accountID)
{
    tuple<bool, Account*> accountRef = AccountGet(accountID); // Declare the account to be added to the list.
    if (get<0>(accountRef)) // Check if the object exists within the account list.
    {
        StateHashUpdate(to_string(accountID)); // Lower the stateHash.
        delete get<1>(accountRef); // Call the account deconstructor.
        AccountsGet()->erase(accountID); // Erase the entry in the list.
        return true;
    }
    else {
        return false;
    }
}

// Return the map containing the transactions.
map<int, Transaction*>* SystemDatabase::TransactionsGet()
{
    return &transactions;
}
// Return the transaction with the given ID.
tuple<bool, Transaction*> SystemDatabase::TransactionGet(int transactionID)
{
    auto it = TransactionsGet()->find(transactionID); // Search for the card in the cards map.
    if (it != TransactionsGet()->end()) { // Check if the card is present in the map.
        return make_tuple(true, it->second);
    }
    else {
        return make_tuple(false, nullptr);
    }
}
// Store the passed transaction.
bool SystemDatabase::TransactionAdd(bool approved, bool archived, int carID, int filerAccountID, int holderAccountID, int transactionID)
{
    tuple<bool, Transaction*> transactionResult = TransactionGet(transactionID); // Declare the account to be added to the list.
    if (!get<0>(transactionResult)) { // Check if an account with the given ID already exists.
        get<1>(transactionResult)->transactionID = transactionID; // Set account parameters.
        StateHashUpdate(to_string(transactionID));
        transactions.insert(make_pair(transactionID, get<1>(transactionResult))); // Insert the account into the map.
        return true;
    }
    else {
        return false;
    }
}
// Delete the transaction with the given ID. Avoid using this for the sake of recordkeeping.
bool SystemDatabase::TransactionDelete(int transactionID)
{
    auto it = TransactionsGet()->find(transactionID); // Get an iterator to the element with the given transactionID.
    if (it != TransactionsGet()->end()) { // Check the iterator to see if the transaction exists.
        StateHashUpdate(to_string(transactionID)); // Lower the stateHash.
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
// Return a list of accountIDs of all accounts with firstnames within the given percentage difference.
// Tolerance is what percentage of the string's name can be different. (e.g. "Steve" with a 0.5 will be only return names fewer than 2.5 characters off.)
vector<int> SystemDatabase::SearchAccount_FNAME(string firstname, float tolerance)
{
    vector<int> foundAccounts;
    for (const auto& account : accounts) { // Iterate through each account.
        // Check if the levenshtein distance between the account's name and given name is less than the percentage of the name's length given (50
        if (LevenshteinDistance(account.second->FirstNameGet(), firstname) <= float(firstname.length()) * tolerance) {
            foundAccounts.push_back(account.second->accountID);
        }
    }
    return foundAccounts;
}
// Return a list of accountIDs of all accounts with firstnames within the given percentage difference.
// Tolerance is what percentage of the string's name can be different. (e.g. "Brown" with a 0.5 will be only return names fewer than 2.5 characters off.)
vector<int> SystemDatabase::SearchAccount_LNAME(string lastname, float tolerance)
{
    vector<int> foundAccounts;
    for (const auto& account : accounts) { // Iterate through each account.
        // Check if the levenshtein distance between the account's name and given name is less than the percentage of the name's length given (50
        if (LevenshteinDistance(account.second->LastNameGet(), lastname) <= 6 * tolerance) {
            foundAccounts.push_back(account.second->accountID);
        }
    }
    return foundAccounts;
}

// Serialization

// Update the hash using the given data.
void SystemDatabase::StateHashUpdate(string data)
{
    for (size_t i = 0; i < data.size(); i++) {
        stateHash += data[i] * 5641 + 17;
    }
}

// Update the database stored on disk (through Boost).
bool SystemDatabase::DBWrite()
{
    ofstream writer("dbCore"); // Create a writer to the database file.
    boost::archive::text_oarchive ofarchiveEndpoint(writer); // Create an endpoint for the ofarchive writer.
    ofarchiveEndpoint << this; // Write this DB to the file.
    StateWrite(); // Update the saved hash state.
    return true;
}
// Read the current database state (through Boost).
bool SystemDatabase::DBRead(SystemDatabase* thisptr)
{
    // !! TO-DO: Version checking using statecheck.
    SystemDatabase newDB; // Create the new instance of SystemDatabase.
    ifstream reader("dbCore"); // Create a reader of the database file.
    boost::archive::text_iarchive ifarchiveEndpoint(reader); // Create an endpoint for the ifarchive reader.
    ifarchiveEndpoint >> newDB; // Load the stored database to the pointer.
    
    SystemDatabase* oldDB = thisptr; // Create a reference to the old database.
    thisptr = &newDB; // Create a new database.
    delete oldDB; // Destroy the old database to avoid any memory issues.

    return true; // Changes were recieved.
}
// Check if a database exists yet.
bool SystemDatabase::DBExists()
{
    return boost::filesystem::exists("dbCore");
}

// Update the current stateHash written to drive.
bool SystemDatabase::StateWrite()
{
    if (!StateCheck()) { // Check if the hash has changed.
        {
            ofstream writer; // Create an ofstream.
            writer.open("dbHash", ios::out | ios::trunc); // Open the hash file.
            writer << stateHash; // Write the current hash.
            return true; // Return true- we wrote a new hash.
        }
    }
    else {
        return false; // Return false- we didn't write a new hash.
    }
}
// Read the current stateHash written to drive.
bool SystemDatabase::StateCheck()
{
    if (!StateExists())
        return false;

    int checkHash = 0; // Create a variable to hold the hash.
    {
        ifstream reader("dbHash"); // Read the state hash file.
        reader >> checkHash; // Store the data to the int.
    }
    return checkHash == stateHash; // Check if the saved hash is the same as the local one.
}
// Check if a stateHash file exists.
bool SystemDatabase::StateExists()
{
    return boost::filesystem::exists("dbHash");
}