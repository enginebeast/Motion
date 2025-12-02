#include <iostream>
#include <fstream>
using namespace std;

void printArray(double* arr, int size);
void printMatrix(double** Matrix, int row, int col);

int main(void) {
	ifstream myfile;
	myfile.open("matrix.txt");

	int size = 3;
	double** matrix = new double* [size];
	for (int i = 0; i < size; i++) {
		matrix[i] = new double[size + 1]();
	}

	//Read file
	if (myfile.is_open()) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size + 1; j++)
				myfile >> matrix[i][j];
		}
	}
	myfile.close();

	cout << "Original matrix\n";
	printMatrix(matrix, size, size + 1);
	cout << "\n";
	
	//Get upper trianglular matrix
	double division;
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			division = matrix[j][i] / matrix[i][i];
			for (int k = 0; k < size + 1; k++)
				matrix[j][k] -= matrix[i][k] * division;
		}
	}

	cout << "Upper triangular matrix\n";
	printMatrix(matrix, size, size + 1);
	cout << "\n";
	
	//Get solution
	double* solution = new double[size]();
	for (int i = size - 1; i >= 0; i--) {
		solution[i] = matrix[i][size];
		for (int j = size - 1; j > i; j--)
			solution[i] -= matrix[i][j] * solution[j];
		solution[i] /= matrix[i][i];
	}

	cout << "Solutions" << "\n";
	for (int i = 0; i < size; i++) 
		cout << solution[i] << " ";
	
	//Free allocation
	for (int i = 0; i < size; i++)
		delete[] matrix[i];
	delete[] matrix;

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