// Get the minimum of three integers.
static int FastMin(int a, int b, int c) {
	int m1 = (a > b) ? b : a; // Get the minimum of the first two.
	return (m1 > c) ? c : m1; // Get the minimum of the smaller and the third.
}