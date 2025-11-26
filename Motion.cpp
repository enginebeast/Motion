#include <iostream>
#include<utility>
using namespace std;

void printArray(double* arr, int size);
void printMatrix(double** Matrix, int row, int col);

int main(void) {
	int size;
	cout << "Input size of matrix\n";
	cin >> size;

	//matrix A
	double** A = new double* [size];
	for (int i = 0; i < size; i++) {
		A[i] = new double[size]();
	}

	cout << "Input matrix A\n";
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			cin >> A[i][j];
	}

	//Vector C
	double* C = new double[size]();
	cout << "Input vector C\n";
	for (int i = 0; i < size; i++)
		cin >> C[i];
	
	
	//Swap
	double** temp = new double* [size];
	for (int i = 0; i < size; i++) {
		temp[i] = new double[size]();
	}
	temp[0][0] = A[1][1];
	temp[1][1] = A[0][0];
	temp[0][1] = A[1][0] * -1;
	temp[1][0] = A[0][1] * -1;

	//Devide detA
	double detA = A[0][0] * A[1][1] - A[0][1] * A[1][0];
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			temp[i][j] /= detA;
	}

	//Solve
	double* B = new double[size]();
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			B[i] += temp[i][j] * C[j];
	}

	printArray(B, size);

	return 0;
}

void printArray(double* arr, int size) {
	for (int i = 0; i < size; i++) 
		cout << arr[i] << " ";
}

void printMatrix(double** Matrix, int row, int col) {
	for (int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++)
			cout << Matrix[i][j] << " ";
		cout << "\n";
	}
	
	cout << "\n";
}