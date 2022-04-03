#pragma once
#include <string>
#include <map>
#include "CreditCard.h"

struct Sensitive {
	int ssn;
	std::map<int, CreditCard*> cards;
};