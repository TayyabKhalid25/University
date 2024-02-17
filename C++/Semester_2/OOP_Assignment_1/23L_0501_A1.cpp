#include <iostream>
#include <fstream>
using namespace std;

// Function Declarations:
char* input_User();
char* input_File();
void tokenization(char*& inputArray, char**& dictionary, int& dictionarySize);
bool check_Dictionary(char**& dictionary, const int& dictionarySize, char*& word, const int& wordLength);
void add_Dictionary(char**& dictionary, const int& dictionarySize, char*& word, const int& wordLength);
void print_Dictionary(char**& dictionary, const int& dictionarySize);
int countArray(char*& arr);
void delete_2DArray(char**& array, int& rows);


int main()
{
	// Task 1:
	char** dictionary = nullptr;  // Declaration of Dictionary.
	int dictionarySize = 0;  // Declaration of how many words in dictionary.

	//char* inputArray = input_User();  // Function for taking input.
	char* inputArray = input_File();  // Alternate Function for reading from file.

	// Tokenization function, includes add dictionary function, compare dictionary function.
	tokenization(inputArray, dictionary, dictionarySize);  

	// Print number of Unique Words in dictionary and then the words themselves.
	print_Dictionary(dictionary, dictionarySize);  
	

	// Task 2:


	// Task 3:
	char* p2 = input_User();  // Take input from user.

	tokenization(p2, dictionary, dictionarySize);  // Same tokenization function.

	print_Dictionary(dictionary, dictionarySize);  // Same Print function.


	// Task 4:



	// Delete Arrays:
	delete[] inputArray; 
	inputArray = nullptr;
	delete[] p2;
	p2 = nullptr;
	delete_2DArray(dictionary, dictionarySize);  // Delete Function.
	
	return 0;
}

//  Function Definitions:

char* input_File()
{
	char* inputArray = new char[3000] {'\0'};
	ifstream input("InputFile.txt");
	input.getline(inputArray, 3000);
	input.close();
	
	cout << "The following is the input from the file:\n";
	cout << inputArray << "\n\n";

	return inputArray;
}

char* input_User()
{
	char* inputArray = new char[3000] {'\0'};  // Intitialisation with nullptr prevents errors in single word entries.

	cout << "Enter a Sentence: \n";
	cin.getline(inputArray, 3000);
	cout << "\n\n";

	return inputArray;
}

void tokenization(char*& inputArray, char**& dictionary, int& dictionarySize)
{
	for (int i = 0; i < 3000 && *(inputArray + i) != '\0'; i++)  // This i++ skips non alphanumeric characters, if not \0.
	{
		char* word = new char[20] {'\0'};  // Initialise with null pointer, 20 is limit of characters in a word.
		int wordLength = 0;

		while (isalnum(*(inputArray + i)))  // Forms words from sentence, no specific delimiter since 
		{									// dictionary should not contain '.', '?'.
			*(word + wordLength++) = *(inputArray + i++);  // This i++ browses the sentence.
		}

		// Checks if word is formed and whether it already exists in dictionary.
		if (wordLength != 0 && check_Dictionary(dictionary, dictionarySize, word, wordLength)) 
		{
			// Dictionary size is post incremented and wordlength is pre incremented to accomodate null pointer.
			add_Dictionary(dictionary, dictionarySize++, word, ++wordLength); // Add to dictionary function
		}

		delete[] word;
	}
	cout << "Dictionary has been updated.\n\n";
}

bool check_Dictionary(char**& dictionary, const int& dictionarySize, char*& word, const int& wordLength)
{
	for (int i = 0; i < dictionarySize; i++)
	{
		int sameLetters = 0;
		for (int j = 0; j < wordLength; j++)
		{
			if (tolower(*(*(dictionary + i) + j)) == tolower(*(word + j)))  // Check each character.
				sameLetters++;
		}
		if (sameLetters == wordLength)  // All letters are same, hence same word.
			return false;
	}
	return true;
}

void add_Dictionary(char**& dictionary, const int& dictionarySize, char*& word, const int& wordLength)
{
	char** temp = dictionary;
	dictionary = new char* [dictionarySize + 1];
	
	for (int i = 0; i < dictionarySize; i++)  // Copies existing words into expanded dictionary.
	{
		*(dictionary + i) = *(temp + i);
	}
	
	*(dictionary + dictionarySize) = new char[wordLength] {'\0'};  // Declare new word's array.
	
	for (int i = 0; i < wordLength; i++)  // Copying word into dictionary.
	{
		*(*(dictionary + dictionarySize) + i) = *(word + i);
	}

	if (temp)  // Ensures not nullptr pointer.
	{
		delete[] temp;  // Delete old dictionary.
	}
}

void print_Dictionary(char**& dictionary, const int& dictionarySize)
{
	cout << "There are " << dictionarySize << " unique words in the given input. They are as follows:\n";
	for (int i = 0; i < dictionarySize; i++)
	{
		cout << *(dictionary + i) << endl;
	}
	cout << "\n\n";
}

void synonyms(char **& dictionary, const int& dictionarySize, char***& synonyms, int*& synonymCount)
{
	// Function for creating/appending synonyms array with dictionary size.

	for (int i = 0; i < dictionarySize; i++)
	{
		char Answer;
		cout << "Do you want to store synonyms for \"" << *(dictionary + i) << "\" in the dictionary?\n(Y/N): ";
		cin >> Answer;
		if (Answer)
		{

		}
		// ask if want to synonym, then how many synonym, then update synonym count and array, then get synonym from user,
		// update synonym array with length of string, copy string into array, repeat till synonym count finished, repeat till end of
		// dictionary size.
		
	}

}

int countArray(char*& arr)
{
	int count = 0;
	while (*(arr + count) != '\0')  // Counts till end of array, excludes nullptr.
		count++;
	return count;
}

void delete_2DArray(char**& arr, int& rows)
{
	if (arr)
	{
		for (int i = 0; i < rows; i++)
		{
			delete[] * (arr + i);
		}
		delete[] arr;
		arr = nullptr;
	}
}