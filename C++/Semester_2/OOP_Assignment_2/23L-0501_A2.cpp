#include <iostream>
#include <fstream>
using namespace std;
#define MaxChar 80

// Function Declarations:
int** InputMatrix(ifstream& fin, int& rows, int& cols);
void OutputMatrix(int** matrix, const int& ROWS, const int& COLS);
int** AddMatrix(int** matrixA, int** matrixB, const int& ROWS, const int& COLS);
int** TransposeMatrix(int** matrix, const int& ROWS, const int& COLS);
bool IsSymmetric(int** matrix, const int& ROWS, const int& COLS);
void InterchangeRows(int** matrix, const int& ROWS, const int& COLS);
void InterchangeRows(int*& row1, int*& row2);
void delete_2DArray(int**& arr, const int& rows);
void fileInput(ifstream& fin, char*& str1, char*& str2);
int stringLength(char* str);
void StringConcatenate(char*& str1, char* str2);
char** StringTokens(char* sentence, int& tokenSize);
bool isSpace(const char& character);
char to_Lower(const char& character);
void add_Word(char**& tokens, const int& tokensSize, char* word, const int& wordLength);
char** InverseStringTokens(char* sentence, int& tokenSize);
char* ReverseSentence(char* sentence);
int CompareString(char* cstring1, char* cstring2);
void DisplayStringList(char** list, const int& listSize);

void studentList();

void sortNames(char** list, const int& listSize);

void swapNames(char*& name1, char*& name2);

int main()
{
	// PART 1: (Matrix Manipulation)

	int rowsA, colsA, rowsB, colsB, rowsC, colsC;  // rowsA => rows of matrixA, rowsB => rows of matrixB. 
	ifstream fin("InputFile.txt");

	// Forming matrices from file:
	int** matrixA = InputMatrix(fin, rowsA, colsA);
	int** matrixB = InputMatrix(fin, rowsB, colsB);
	int** matrixC = InputMatrix(fin, rowsC, colsC);

	// Printing of Matrices from file:
	cout << "Matrix A =\n";
	OutputMatrix(matrixA, rowsA, colsA);

	cout << "\nMatrix B =\n";
	OutputMatrix(matrixB, rowsB, colsB);

	cout << "\nMatrix C =\n";
	OutputMatrix(matrixC, rowsC, colsC);

	// Printing of Addition of Matrices:
	cout << "\nA + B =\n";
	int** matrixAB = AddMatrix(matrixA, matrixB, rowsA, colsA);
	OutputMatrix(matrixAB, rowsA, colsA);

	cout << "\nA + C =\n";
	int** matrixAC = nullptr;
	if (rowsA == rowsC && colsA == colsC)
	{
		matrixAC = AddMatrix(matrixA, matrixC, rowsA, colsA);
		OutputMatrix(matrixAC, rowsA, colsA);
	}
	else
		cout << "\nAddition not possible.\n";

	// Printing Transpose of matrices:
	cout << "\nTranspose of A =\n";
	int** transposeA = TransposeMatrix(matrixA, rowsA, colsA);
	OutputMatrix(transposeA, colsA, rowsA);  // Rows and cols are swapped in transpose.

	cout << "\nTranspose of C =\n";
	int** transposeC = TransposeMatrix(matrixC, rowsC, colsC);
	OutputMatrix(transposeC, colsC, rowsC);  // Rows and cols are swapped in transpose.

	// Testing Symmetry of matrices:
	if (IsSymmetric(matrixA, rowsA, colsA))
		cout << "\nMatrix A is Symmetric\n";
	else
		cout << "\nMatrix A is NOT Symmetric\n";

	if (IsSymmetric(matrixB, rowsB, colsB))
		cout << "\nMatrix B is Symmetric\n";
	else
		cout << "\nMatrix B is NOT Symmetric\n";

	// Printing matrix after interchanging rows of matrix A:
	InterchangeRows(matrixA, rowsA, colsA);
	cout << "After interchanging rows of Matrix A =\n";
	OutputMatrix(matrixA, rowsA, colsA);

	// Deleting All arrays formed on heap, and closing file:
	fin.close();
	delete_2DArray(matrixA, rowsA);
	delete_2DArray(matrixB, rowsB);
	delete_2DArray(matrixC, rowsC);
	delete_2DArray(matrixAB, rowsA);
	delete_2DArray(matrixAC, rowsA);
	delete_2DArray(transposeA, colsA);  
	delete_2DArray(transposeC, colsC);

	// PART 2: (String Manipulation)




	return 0;
}

// Function Definitions:
int** InputMatrix(ifstream& fin, int& rows, int& cols)
{
	fin >> rows >> cols;
	int** matrix = new int* [rows];
	for (int i = 0, **arrR = matrix; i < rows; i++, arrR++)  // Array Rows represents 1st Dimension of matrix.
	{
		*arrR = new int[cols];
		for (int j = 0, *arrC = *arrR; j < cols; j++, arrC++)  // Array Columns represents 2nd Dimension of matrix.
			fin >> *arrC;  // Populate Matrix with input from file.
	}
	return matrix;
}

void OutputMatrix(int** matrix, const int& ROWS, const int& COLS)
{
	if (matrix)  // Checks if not nullptr.
	{
		cout << "The Matrix contains the following contents:\n";
		for (int i = 0, **arrR = matrix; i < ROWS; i++, arrR++)
		{
			for (int j = 0, *arrC = *arrR; j < COLS; j++, arrC++)
				cout << *arrC << ' ';
			cout << endl;
		}
	}
}

int** AddMatrix(int** matrixA, int** matrixB, const int& ROWS, const int& COLS)
{
	int** newMatrix = new int* [ROWS] {nullptr};
	// arrRA => rows of matrixA, arrRB => rows of matrixB, newR => rows of newMatrix.
	for (int i = 0, **arrRA = matrixA, **arrRB = matrixB, **newR = newMatrix; i < ROWS; i++, arrRA++, arrRB++, newR++)
	{
		*newR = new int[COLS];
		// arrCA => cols of matrixA, arrCB => cols of matrixB, newC => cols of newMatrix.
		for (int j = 0, *arrCA = *arrRA, *arrCB = *arrRB, *newC = *newR; j < COLS; j++, arrCA++, arrCB++, newC++)
			*newC = *arrCA + *arrCB;  // Adds corresponding elements of matrixA and matrixB and stores in newMatrix.
	}
	return newMatrix;
}

int** TransposeMatrix(int** matrix, const int& ROWS, const int& COLS)
{
	// In Transpose, rows are swapped with columns.
	int** transpose = new int* [COLS];
	for (int i = 0; i < COLS; i++) 
	{
		*(transpose + i) = new int[ROWS];
		for (int j = 0; j < ROWS; j++)
			*(*(transpose + i) + j) = *(*(matrix + j) + i);
	}
	return transpose;
}

bool IsSymmetric(int** matrix, const int& ROWS, const int& COLS) 
{
	if (ROWS == COLS)
	{
		int** transpose = TransposeMatrix(matrix, ROWS, COLS);
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				if (*(*(matrix + i) + j) != *(*(transpose + i) + j))
					return false;  // Element(s) not equal, not symmetric.
			}
		}
		return true;  // All elements are equal, hence symmetric.
	}
	else
		return false;  // Matrix is not a square matrix, hence not symmetric.
}

void InterchangeRows(int** matrix, const int& ROWS, const int& COLS)
{
	int row1 = 0, row2 = 2;
	cout << "\nInterchanging Rows of Matrix A:\nrow1: " << row1 + 1 << "\nrow2: " << row2 + 1 << endl;

	InterchangeRows(*(matrix + row1), *(matrix + row2));
}

void InterchangeRows(int*& row1, int*& row2)
{
	int* temp = row1;
	row1 = row2;
	row2 = temp;
}

void delete_2DArray(int**& arr, const int& rows)
{
	if (arr)  // Checks if array is not nullptr.
	{
		for (int i = 0; i < rows && *(arr + i); i++)  // Checks if each index contains pointer to array, and not nullptr.
			delete[] * (arr + i);
		delete[] arr;
		arr = nullptr;
	}
}

void fileInput(ifstream& fin, char*& str1, char*& str2)
{
	char* inputBuffer = new char[MaxChar];  // TempBuffer for instantiating cstrings with exact character length.
	fin.getline(inputBuffer, MaxChar);
	
	int length = stringLength(inputBuffer);
	str1 = new char[length + 1];  // +1 to accomodate '\0'.
	for (int i = 0; i < length + 1; i++)
		str1[i] = inputBuffer[i];

	fin.getline(inputBuffer, MaxChar);

	length = stringLength(inputBuffer);
	str2 = new char[length + 1];  // +1 to accomodate '\0'.
	for (int i = 0; i < length + 1; i++)
		str2[i] = inputBuffer[i];

	delete[] inputBuffer;
}

int stringLength(char* str)  // Returns string length till nullptr.
{
	int len = 0;
	while (str[len] != '\0')
		len++;

	return len;
}

void StringConcatenate(char*& str1, char* str2)  // Calculates length of appended array, then replaces str1 with appended array.
{
	char* temp = str1;
	int length1 = stringLength(str1), length2 = stringLength(str2);
	int newLength = length1 + length2;
	str1 = new char[newLength + 1];  // +1 for '\0'.

	for (int i = 0; i < length1; i++)  // Copies str1 into new array.
		str1[i] = temp[i];
	for (int i = length1; i < newLength + 1; i++)  // newlength + 1 to also copy '\0'.
		str1[i] = str2[i - length1];  // i - length for starting at proper index of str2, and copying into new array.
	
	delete[] temp;  // Delete old array.
}

char** StringTokens(char* sentence, int& tokenSize)
{
	char** tokens = nullptr;
	for (int i = 0; sentence[i] != '\0'; i++)  // This i++ skips space characters, if not \0.
	{
		char* word = new char[MaxChar] {'\0'};  
		int wordLength = 0;

		while (!isSpace(*(sentence + i)))  // Forms words from sentence, delimiter is space. 
			word[wordLength++] = sentence[i++];  // This i++ browses the sentence.

		// Checks if word is formed.
		if (wordLength != 0)
			// Token size is post incremented and wordlength is pre incremented to accomodate null pointer.
			add_Word(tokens, tokenSize++, word, ++wordLength); // Add to 2D array tokens.
		delete[] word;
	}

	return tokens;
}

bool isSpace(const char& character)
{
	if (character == ' ' || character == '\t' || character == '\n')
		return true;
	return false;  // else return false.
}

char to_Lower(const char& character)
{
	if (character >= 'A' && character <= 'Z')
		return (character - ('A' - 'a'));
	return character;  // else return as is.
}

void add_Word(char**& tokens, const int& tokenSize, char* word, const int& wordLength)
{
	char** temp = tokens;
	tokens = new char* [tokenSize + 1];

	for (int i = 0; i < tokenSize; i++)  // Copies existing words into expanded array.
		tokens[i] = temp[i];

	tokens[tokenSize] = new char[wordLength];  // Declare new word's array.

	for (int i = 0; i < wordLength; i++)  // Copying word into tokens.
		tokens[tokenSize][i] = word[i];

	if (temp)  // Ensures not nullptr pointer.
		delete[] temp;  // Delete old array.
}

char** InverseStringTokens(char* sentence, int& tokenSize)
{
	char** tokens = StringTokens(sentence, tokenSize);
	
	for (int i = 0; i < tokenSize / 2; i++)  // Runs till half of array, replacing 1st element with last, 2nd with 2nd last, etc.
	{
		char* temp = tokens[i];
		tokens[i] = tokens[tokenSize - i];
		tokens[tokenSize - i] = temp;
	}

	return tokens;
}

char* ReverseSentence(char* sentence)
{
	int tokenSize = 0;
	char** tokens = InverseStringTokens(sentence, tokenSize);
	int length = stringLength(sentence);
	char* newSentence = new char[length + 1];  // +1 for '\0'.

	// i represents index of sentence, currentToken is the current word being copied into sentence. 
	int i = 0;
	for (int currentToken = 0; currentToken < tokenSize; currentToken++)  
	{
		int wordLength = stringLength(tokens[i]);
		for (int j = 0; j < wordLength; j++)
			newSentence[i++] = tokens[currentToken][j];  // j is index of current token/word, i is incremented to parse next char.
		newSentence[i++] = ' ';  // Appends space b/w each word.
	}
	newSentence[i] = '\0';  // Ends sentence with nullptr.

	return newSentence;
}

int CompareString(char* cstring1, char* cstring2)
{
	int length1 = stringLength(cstring1), length2 = stringLength(cstring2), lowerLength;
	// Lower length needed to prevent out of bounds access.
	if (length1 < length2)
		lowerLength = length1;
	else
		lowerLength = length2;

	for (int i = 0; i < lowerLength; i++)
	{
		if (to_Lower(cstring1[i]) > to_Lower(cstring2[i]))  // cstring1 > cstring2, hence return 1.
			return 1;
		else if (to_Lower(cstring1[i]) < to_Lower(cstring2[i]))  // cstring1 < cstring2, hence return -1.
			return -1;
	}
	// cstring1 == cstring2, hence return 0.
	return 0;
	// A(65) < B(66), so if cstring1 > cstring2, it means cstring2 comes first alphabetically.
}

void DisplayStringList(char** list, const int& listSize)
{
	for (int i = 0; i < listSize; i++)
		cout << i + 1 << ")\t" << list[i] << endl;
}

void studentList()
{
	char** list = nullptr;
	int listSize = 0;
	// Read all names from file and add into list.
	ifstream fin("Data.txt");
	while (!fin.eof())
	{
		char* name = new char[MaxChar] {'\0'};
		fin.getline(name, MaxChar);
		int nameLength = stringLength(name);

		if (nameLength != 0)
			// List size is post incremented and namelength is pre incremented to accomodate null pointer.
			add_Word(list, listSize++, name, ++nameLength); // Same function used as tokenization.

		delete[] name;
	}
	fin.close();

	cout << "\nList BEFORE sorting:\n";
	DisplayStringList(list, listSize);

	sortNames(list, listSize);  // Sorts names alphabetically.

	cout << "\nList AFTER sorting:\n";
	DisplayStringList(list, listSize);
}

void sortNames(char** list, const int& listSize)
{
	for (int i = 0; i < listSize; i++)  // Selection Sort:
	{
		int lowest = i;
		for (int j = i + 1; j < listSize; j++)
		{
			if (CompareString(list[lowest], list[j]) == 1)  // list[lowest] > list[j], hence new lowest found.
				lowest = j;
		}
		swapNames(list[i], list[lowest]);
	}
}

void swapNames(char*& name1, char*& name2)
{
	char* temp = name1;
	name1 = name2;
	name2 = temp;
}

void CompressString(char* cstring)
{
	int length = stringLength(cstring);
	for (int i = 0; i < length; i++)
	{
		while (cstring[i])
		{

		}
	}
}
