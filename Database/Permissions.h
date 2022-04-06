#pragma once

struct Permissions {
	// Is the account allow to manage transactions?
	bool manageTransaction = false;
	// Is the account allowed to manage cars?
	bool manageCar = false;
	// Is the account allowed to manage accounts?
	bool manageAccount = false;
};