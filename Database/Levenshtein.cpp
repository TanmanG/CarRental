#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <sstream>
#include "FastMin.cpp"
using namespace std;

// Get the Levenshtein Distance between two strings.
static int LevenshteinDistance(string s1, string s2)
{
	vector<vector<int>> solutionMatrix(s2.size() + 1, vector<int>(s1.size() + 1)); // Declare the matrix that will hold the solution.

	if (s1[0] == s2[0]) { // Check if the first characters are equal.
		solutionMatrix[0][0] = 0; // Set the starting index to zero.
	}
	else {
		solutionMatrix[0][0] = 1; // Set the matrix's starting value to one.
	}

	for (size_t m = 1; m < s1.length(); m++) { // Iterate through S1 to create Y base of matrix.
		solutionMatrix[0][m] = solutionMatrix[0][m - 1] + 1; // Set the matrix value equal to the last index plus one.
	}
	for (size_t n = 1; n < s2.length(); n++) { // Iterate through S2 to create X base of matrix.
		solutionMatrix[n][0] = solutionMatrix[n - 1][0] + 1; // Set the matrix value equal to the last index plus one.
	}
	
	for (size_t m = 0; m < s1.length() - 1; m++) { // Iterate through each Y unit on the matrix.
		for (size_t n = 0; n < s2.length() - 1; n++) { // Iterate through each X unit on the matrix.
			if (s1[m] == s2[n]) { // Check if the letter at this spot is the same.
				// Case A: The current left letter is equal to the current top letter.
				solutionMatrix[n + 1][m + 1] = FastMin(solutionMatrix[n][m], solutionMatrix[n + 1][m], solutionMatrix[n][m + 1]);
			}
			else {
				// Case B: The current left letter is not equal to the current top letter.
				solutionMatrix[n + 1][m + 1] = FastMin(solutionMatrix[n][m], solutionMatrix[n + 1][m], solutionMatrix[n][m + 1]) + 1;
			}
		}
		
	}

	return solutionMatrix.back().back(); // Return the bottom-right-most element on the matrix.
}