#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(vector<double> a, vector<double> b);
void printMatrix(vector<vector<double>> matrix, int row, int col);
double findFirstZero(vector<double> v, int size);

int main(void) {
	ifstream myfile;
	myfile.open("matrix.txt");

	//matrix[size] is constant
	//matrix[size+1] is firstZeroIndex
	int size = 3;
	vector<vector<double>> matrix(size, vector<double>(size + 2, 0));

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
	
	//Sorting
	for (int i = 0; i < size; i++) {
		matrix[i][size+1] = findFirstZero(matrix[i], size);
	}
	sort(matrix.begin(), matrix.end(), compare);

	cout << "Sorting matrix by first zero\n";
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
	cout << "\n";
	
	//Free allocation
	delete[] solution;

	return 0;
}

bool compare(vector<double> a, vector<double> b) {
	double lastIndex = a.size() - 1;
	return a[lastIndex] > b[lastIndex];
}

void printMatrix(vector<vector<double>> matrix, int row, int col) {
	for (int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++)
			cout << matrix[i][j] << " ";
		cout << "\n";
	}
	
	cout << "\n";
}

double findFirstZero(vector<double> v, int size) {
	for (int i = 0; i < size; i++) {
		if (v[i] == 0)
			return size;
	}
	return 1e9;
}