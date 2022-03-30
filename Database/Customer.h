#pragma once
#include "Address.h"
#include "Contact.h"
#include "Sensitive.h"

struct Customer {
	Sensitive sensitiveInfo;
	Contact contactInfo;
	Address addressInfo;
};