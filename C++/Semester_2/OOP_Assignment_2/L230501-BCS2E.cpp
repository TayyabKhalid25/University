#include <iostream>
#include <fstream>
using namespace std;

// Function Declarations:
int** InputMatrix(ifstream& fin, int& rows, int& cols);
void OutputMatrix(int** matrix, const int& ROWS, const int& COLS);
int** AddMatrix(int** matrixA, int** matrixB, const int& ROWS, const int& COLS);
int** TransposeMatrix(int** matrix, const int& ROWS, const int& COLS);
bool IsSymmetric(int** matrix, const int& ROWS, const int& COLS);
void InterchangeRows(int** matrix, const int& ROWS, const int& COLS);
void InterchangeRows(int*& row1, int*& row2);

int main()
{


	return 0;
}

// Function Definitions:
int** InputMatrix(ifstream& fin, int& rows, int& cols)
{
	fin >> rows >> cols;
	int** matrix = new int* [rows];
	for (int i = 0, int** arrR = matrix; i < rows; i++, arrR++)  // Array Rows represents 1st Dimension of matrix.
	{
		*arrR = new int[cols];
		for (int j = 0, int* arrC = *arrR; j < cols; j++, arrC++)  // Array Columns represents 2nd Dimension of matrix.
			fin >> *arrC;  // Populate Matrix with input from file.
	}
	return matrix;
}

void OutputMatrix(int** matrix, const int& ROWS, const int& COLS)
{
	cout << "The Matrix contains the following contents:\n";
	for (int i = 0, int** arrR = matrix; i < ROWS; i++, arrR++)  
	{
		for (int j = 0, int* arrC = *arrR; j < COLS; j++, arrC++)
			cout << *arrC << ' ';
		cout << endl;
	}
}

int** AddMatrix(int** matrixA, int** matrixB, const int& ROWS, const int& COLS)
{
	try
	{
		int** newMatrix = new int* [ROWS];
		// arrRA => rows of matrixA, arrRB => rows of matrixB, newR => rows of newMatrix.
		for (int i = 0, int** arrRA = matrixA, int** arrRB = matrixB, int** newR = newMatrix; i < ROWS; i++, arrRA++, arrRB++, newR++)
		{
			*newR = new int[COLS];
			// arrCA => cols of matrixA, arrCB => cols of matrixB, newC => cols of newMatrix.
			for (int j = 0, int* arrCA = *arrRA, int* arrCB = *arrRB, int* newC = *newR; j < COLS; j++, arrCA++, arrCB++, newC++)
				*newC = *arrCA + *arrCB;  // Adds corresponding elements of matrixA and matrixB and stores in newMatrix.
		}
		return newMatrix;
	}
	catch (const exception&)
	{
		cout << "Addition not possible.\n";
	}
}

int** TransposeMatrix(int** matrix, const int& ROWS, const int& COLS)
{
	int** transpose = new int* [COLS];
	for (int i = 0; i < COLS; ++i)
		transpose[i] = new int[ROWS];

	for (int i = 0; i < ROWS; ++i)
		for (int j = 0; j < COLS; ++j)
			transpose[j][i] = matrix[i][j];

	return transpose;
}

bool IsSymmetric(int** matrix, const int& ROWS, const int& COLS) 
{

}

void InterchangeRows(int** matrix, const int& ROWS, const int& COLS)
{

}

void InterchangeRows(int*& row1, int*& row2)
{

}
