#pragma once
#include <string>
#include <vector>
#include "CreditCard.h"

struct Sensitive {
	int ssn;
	std::vector<CreditCard> cards;
};