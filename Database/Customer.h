#pragma once
#include "Address.h"
#include "Contact.h"
#include "Sensitive.h"

struct Customer {
	// Struct holding sensitive info (!! ENCRPYT)
	Sensitive sensitiveInfo;
	// Contact information of the customer.
	Contact contactInfo;
	// Address information of the customer.
	Address addressInfo;
};