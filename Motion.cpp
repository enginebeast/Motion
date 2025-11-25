#include <iostream>
#include<utility>
using namespace std;

void printMatrix(double** Matrix, int size);

int main(void) {
	//2 x 2 matrix
	double** A = new double* [2];
	for (int i = 0; i < 2; i++) {
		A[i] = new double[2];
	}
	A[0][0] = 1; 
	A[0][1] = 2;
	A[1][0] = 2;
	A[1][1] = 1;

	double C[2] = { 7, 4 };
	double detA = A[0][0] * A[1][1] - A[0][1] * A[1][0];
	
	//Adj
	swap(A[0][0], A[1][1]);
	swap(A[0][1], A[1][0]);
	A[0][1] *= -1;
	A[1][0] *= -1;

	printMatrix(A, 2);
	
	cout << detA << "\n";

	return 0;
}

void printMatrix(double** Matrix, int size) {
	for (int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++)
			cout << Matrix[i][j] << " ";
		cout << "\n";
	}
	
	cout << "\n";
}