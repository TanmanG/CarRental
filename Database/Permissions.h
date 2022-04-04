#pragma once

struct Permissions {
	// Is the account allow to manage transactions?
	bool manageTransaction;
	// Is the account allowed to manage cars?
	bool manageCar;
	// Is the account allowed to manage accounts?
	bool manageAccount;
};