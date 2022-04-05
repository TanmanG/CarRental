#include <string>
#include "FastMin.cpp"
using namespace std;

// Get the Levenshtein Distance between two strings- recursive.
static unsigned int LevenshteinDistance(string str1, string str2) {
	size_t strLenA = str1.length();
	size_t strLenB = str2.length();

	if (strLenA == 0) { // Catch 0 length string 2.
		return strLenB;
	}
	if (strLenB == 0) { // Catch 0 length string 1.
		return strLenA;
	}

	int cost;
	if (str1[strLenA - 1] == str2[strLenB - 1]) {
		cost = 0;
	}
	else {
		cost = 1;
	}

	return FastMin(LevenshteinDistance(str1.substr(0, strLenA - 1), str2) + 1,
					LevenshteinDistance(str1, str2.substr(0, strLenB - 1)) + 1,
					LevenshteinDistance(str1.substr(0, strLenA - 1), str2.substr(0, strLenB - 1)) + cost);
}