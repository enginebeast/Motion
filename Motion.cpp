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
			for (int j = 0; j < size; j++)
				myfile >> matrix[i][j];
		}
	}

	/*
	for (int i = 0; i < size; i++) {
		double tempDiv =  temp[i][0] / temp[i + 1][0];
		for (int j = 0; j < size + 1; j++) {
			temp[i + 1][j] -= temp[i][j] * tempDiv;
		}
	}
	*/

	printMatrix(matrix, size, size + 1);
	
	myfile.close();

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