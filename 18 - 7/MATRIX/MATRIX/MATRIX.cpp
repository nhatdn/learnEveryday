#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void LoadData(int**& A, int& col, int& row, string file) {
	fstream input;
	input.open(file, ios::in);
	input >> col >> row;
	A = new int* [col];
	for (int i = 0; i < col; i++) A[i] = new int[row];
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			input >> A[i][j];
		}
	}
	input.close();
}
void showData(int**& A, int& col, int& row) {
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			cout << A[i][j] << "\t";
		}
		cout << endl;
	}
}
void Draw(int* A[], int* B[], int colB, int colA, int rowA) {
	int result = 0;
	cout << endl;
	for (int i = 0; i < colA; i++) {
		for (int k = 0; k < colB; k++) {
			result = 0;
			for (int j = 0; j <= rowA - 2; j++) {
				result += (A[i][j] * B[j][k]);
				cout << A[i][j] << " * " << B[j][k] << "   +   ";
			}
			result += (A[i][rowA - 1] * B[rowA - 1][k]);
			cout << A[i][rowA - 1] << " * " << B[rowA - 1][k] << "  =  " << result << endl;
		}
		cout << endl;
	}
}
void Processing(int** A, int** B, int colB, int colA, int rowA) {
	int result = 0;
	for (int i = 0; i < colA; i++) {
		for (int k = 0; k < colB; k++) {
			result = 0;
			for (int j = 0; j < rowA; j++) {
				result = result + A[i][j] * B[j][k];
			}
			cout << result << "\t";
		}
		cout << endl;
	}
}

int main() {
	int columnA, rowA;
	int** arrA;
	int columnB, rowB;
	int** arrB;
	cout << "=============== Table A: ===============" << endl;
	LoadData(arrA, columnA, rowA, "inputA.txt");
	showData(arrA, columnA, rowA);
	cout << "=============== Table B: ===============" << endl;
	LoadData(arrB, columnB, rowB, "inputB.txt");
	showData(arrB, columnB, rowB);
	bool checked = false;
	if (columnB == rowA) {
		cout << "=============== Table C: ===============" << endl;
		Draw(arrA, arrB, rowB, columnA, rowA);
		Processing(arrA, arrB, rowB, columnA, rowA);
		checked = true;
	}
	if (columnA == rowB) {
		cout << "=============== Table C: ===============" << endl;
		Draw(arrB, arrA, rowA, columnB, rowB);
		Processing(arrB, arrA, rowA, columnB, rowB);
		checked = true;
	}
	if (checked == false) {
		cout << "Condition require: column A = row B or column B = row A" << endl;
	}
	delete arrA, arrB;
	system("pause");
	return 0;
}

