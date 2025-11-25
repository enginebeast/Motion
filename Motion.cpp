#include <iostream>

int main(void) {
	using namespace std;

	//2 x 2 matrix
	double A[2][2] = { {1, 2}, {2, 1} };
	double detA = A[0][0] * A[1][1] - A[0][1] * A[1][0];
	cout << detA << "\n";

	return 0;
}