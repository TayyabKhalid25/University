#include <iostream>
#include <fstream>
using namespace std;

// Function Declarations:
char* input_User();
char* input_File();
void tokenization(char*& inputArray, char**& dictionary, int& dictionarySize);
bool isAlphaNumeric(const char& character);
int check_Dictionary(char**& dictionary, const int& dictionarySize, char*& word, const int& wordLength);
char to_Lower(const char& character);
void add_Dictionary(char**& dictionary, const int& dictionarySize, char*& word, const int& wordLength);
void print_Dictionary(char**& dictionary, const int& dictionarySize);
void add_Synonyms(char**& dictionary, const int& dictionarySize, char***& synonyms, int*& synonymCount);
void update_Synonyms(char***& synonyms, const int& index, const int& numSynonyms);
int countArray(char*& arr); 
void replace_With_Synonyms(char*& inputArray, char**& dictionary, int& dictionarySize, char***& synonyms, int*& synonymCount, const int& synonymSize);
int print_Select_Choice(char***& synonyms, int*& synonymCount, const int& index);
void replace_Word(char*& inputArray, int& arrayIndex, char*& word, char*& newWord);
void adjust_Sentence(char*& inputArray, int& arrayIndex, int factor);
void delete_2DArray(char**& array, const int& rows);
void delete_3DArray(char***& arr, const int& rows, int*& columns);

int main()
{
	// Task 1:
	cout << "Task 1:\n\n";
	char** dictionary = nullptr;  // Declaration of Dictionary.
	int dictionarySize = 0;  // Declaration of how many words in dictionary.

	char* inputArray = input_User();  // Function for taking input.
	//char* inputArray = input_File();  // Alternate Function for reading from file.

	// Tokenization function, includes add dictionary function, compare dictionary function.
	tokenization(inputArray, dictionary, dictionarySize);  

	// Print number of Unique Words in dictionary and then the words themselves.
	print_Dictionary(dictionary, dictionarySize);  
	

	// Task 2:
	cout << "Task 2:\n\n";
	char*** synonyms = nullptr;  // Declaration of 3D synonyms array.
	int* synonymCount = nullptr;  // Array which stores amount of synonyms of each word in dictionary.

	add_Synonyms(dictionary, dictionarySize, synonyms, synonymCount);
	
	int synonymSize = dictionarySize;  // Since in task 3, dictionary size will change, without appending synonyms.

	// Task 3:
	cout << "\nTask 3:\n\n";
	char* p2 = input_User();  // Take input from user.

	tokenization(p2, dictionary, dictionarySize);  // Tokenization function for updating Dictionary.


	// Task 4:
	cout << "Task 4:\n\n";

	replace_With_Synonyms(p2, dictionary, dictionarySize, synonyms, synonymCount, synonymSize);  // Tokenization but with synonym replacement.

	print_Dictionary(dictionary, dictionarySize);  // Same Print function.


	// Delete Arrays:
	delete[] inputArray; 
	inputArray = nullptr;
	delete_3DArray(synonyms, synonymSize, synonymCount);
	delete[] p2;
	p2 = nullptr;
	delete[] synonymCount;
	synonymCount = nullptr;
	delete_2DArray(dictionary, dictionarySize);  // Delete Function for 2D array.
	
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
	if (cin.peek() == '\0' || cin.peek() == '\n')  // if ignored and nothing in buffer, then first char of input is lost.
		cin.ignore();
	cin.getline(inputArray, 3000);
	cout << endl;

	return inputArray;
}

void tokenization(char*& inputArray, char**& dictionary, int& dictionarySize)
{
	for (int i = 0; i < 3000 && *(inputArray + i) != '\0'; i++)  // This i++ skips non alphanumeric characters, if not \0.
	{
		char* word = new char[20] {'\0'};  // Initialise with null pointer, 20 is limit of characters in a word.
		int wordLength = 0;

		while (isAlphaNumeric(*(inputArray + i)))  // Forms words from sentence, no specific delimiter since 
		// dictionary should not contain '.', '?'. Char is within 'a'-'z', 'A'-'Z', '0'-'9'.
			*(word + wordLength++) = *(inputArray + i++);  // This i++ browses the sentence.

		// Checks if word is formed and whether it already exists in dictionary.
		if (wordLength != 0 && check_Dictionary(dictionary, dictionarySize, word, wordLength) == -1) 
			// Dictionary size is post incremented and wordlength is pre incremented to accomodate null pointer.
			add_Dictionary(dictionary, dictionarySize++, word, ++wordLength); // Add to dictionary function
		delete[] word;
	}
	cout << "Dictionary has been updated.\n\n";
}

bool isAlphaNumeric(const char& character)
{
	if ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z') || (character >= '0' && character <= '9'))
		return true;
	return false;  // else return false.
}

int check_Dictionary(char**& dictionary, const int& dictionarySize, char*& word, const int& wordLength)
{
	for (int i = 0; i < dictionarySize; i++)
	{
	    if (countArray(*(dictionary + i)) == wordLength)  // Ensures that words that are part of other words are not considered the same.
	    {
			int sameLetters = 0;
			for (int j = 0; j < wordLength; j++)
			{
				if (to_Lower(*(*(dictionary + i) + j)) == to_Lower(*(word + j)))  // Check each character.
					sameLetters++;
			}
			if (sameLetters == wordLength)  // All letters are same, hence same word.
				return i;  // Returns index of dictionary where word is located.
	    }
	}
	return -1;
}

char to_Lower(const char& character)
{
	if (character >= 'A' && character <= 'Z')
		return (character - ('A' - 'a'));
	return character;  // else return as is.
}

void add_Dictionary(char**& dictionary, const int& dictionarySize, char*& word, const int& wordLength)
{
	char** temp = dictionary;
	dictionary = new char* [dictionarySize + 1];
	
	for (int i = 0; i < dictionarySize; i++)  // Copies existing words into expanded dictionary.
		*(dictionary + i) = *(temp + i);

	*(dictionary + dictionarySize) = new char[wordLength] {'\0'};  // Declare new word's array.
	
	for (int i = 0; i < wordLength; i++)  // Copying word into dictionary.
		*(*(dictionary + dictionarySize) + i) = *(word + i);

	if (temp)  // Ensures not nullptr pointer.
		delete[] temp;  // Delete old dictionary.
}

void print_Dictionary(char**& dictionary, const int& dictionarySize)
{
	cout << "There are " << dictionarySize << " unique words in the dictionary. They are as follows:\n";
	for (int i = 0; i < dictionarySize; i++)
		cout << *(dictionary + i) << endl;
	cout << "\n\n";
}

void add_Synonyms(char **& dictionary, const int& dictionarySize, char***& synonyms, int*& synonymCount)
{
	synonyms = new char** [dictionarySize] {nullptr};
	synonymCount = new int[dictionarySize] {0};
	for (int i = 0; i < dictionarySize; i++)
	{
		char answer;
		cout << "Do you want to store synonyms for \"" << *(dictionary + i) << "\" in the dictionary?\n(Y/N): ";
		cin >> answer;
		if (to_Lower(answer) == 'y')
		{
			int numSynonyms;
			cout << "How many synonyms do you want to store for \"" << *(dictionary + i) << "\"?: ";
			cin >> numSynonyms;
			*(synonymCount + i) = numSynonyms;
			if (numSynonyms > 0)
			{
				*(synonyms + i) = new char* [numSynonyms] {nullptr};
				update_Synonyms(synonyms, i, numSynonyms);
			}
		}
	}
}

void update_Synonyms(char***& synonyms, const int& index, const int& numSynonyms)
{
	for (int j = 0; j < numSynonyms; j++)
	{
		char* input = new char[20] { '\0' };
		cout << "Enter synonym " << j + 1 << ": ";
		if (cin.peek() == '\0' || cin.peek() == '\n')
			cin.ignore();
		cin.getline(input, 20);
		int charCount = countArray(input);
		*(*(synonyms + index) + j) = new char[charCount + 1] {'\0'};  // +1 for nullptr.
		for (int k = 0; k < charCount; k++)
			*(*(*(synonyms + index) + j) + k) = *(input + k);  // Copy character letter by letter into synonyms.
		delete[] input;
	}
	cout << "\nSynonym(s) stored successfully!\n\n";
}

int countArray(char*& arr)
{
	int count = 0;
	while (*(arr + count) != '\0')  // Counts till end of array, excludes nullptr.
		count++;
	return count;
}

void replace_With_Synonyms(char*& inputArray, char**& dictionary, int& dictionarySize, char***& synonyms, int*& synonymCount, const int& synonymSize)  
{
	for (int i = 0; i < 3000 && *(inputArray + i) != '\0'; i++)  // This i++ skips non alphanumeric characters, if not \0.
	{
		char* word = new char[20] {'\0'};  // Initialise with null pointer, 20 is limit of characters in a word.
		int wordLength = 0;

		while (isAlphaNumeric(*(inputArray + i)))  // Forms words from sentence, no specific delimiter since 
		//dictionary should not contain '.', '?'. Char is within 'a'-'z', 'A'-'Z', '0'-'9'.
			*(word + wordLength++) = *(inputArray + i++);  // This i++ browses the sentence.

		// Checks if word is formed.
		if (wordLength != 0)
		{
			//  Checks whether word already exists in dictionary and it already has a synonym.
			int dictionaryIndex = check_Dictionary(dictionary, dictionarySize, word, wordLength);
			//  Some words may be in dictionary but not in synonyms, hence seperate synonymSize check is needed.
			if (dictionaryIndex >= 0 && dictionaryIndex < synonymSize && *(synonyms + dictionaryIndex) != nullptr) // if found and it has synonyms.
			{
				char answer;
				cout << "Synonym(s) for the word \"" << word << "\" found in dictionary. Would you like to replace it? (Y/N): ";
				cin >> answer;
				if (to_Lower(answer) == 'y')
				{
					// Function which prints synonyms and allows user to enter choice of which to replace with.
					int choice = print_Select_Choice(synonyms, synonymCount, dictionaryIndex);
					if (choice >= 0 && choice < *(synonymCount + dictionaryIndex))
						// Function that replaces synonym with old word in sentence.
						replace_Word(inputArray, i, word, *(*(synonyms + dictionaryIndex) + choice));
				}
			}
		}
		delete[] word;
	}
	cout << "The updated sentence is:\n" << inputArray << "\n\n";
}

int print_Select_Choice(char***& synonyms, int*& synonymCount, const int& index)
{
	cout << "\nThe following synonyms have been found: \n";
	for (int j = 0; j < *(synonymCount + index); j++)
		cout << j + 1 << ")\t" << *(*(synonyms + index) + j) << endl;
	int choice;
	cout << "\nEnter number corresponding to synonym(-1 to exit): ";
	cin >> choice;
	choice--; // Compensates for user friendly index number.
	return choice;
}

void replace_Word(char*& inputArray, int& arrayIndex, char*& word, char*& newWord)
{
	int wordLength = countArray(word);
	int synonymLength = countArray(newWord);
	adjust_Sentence(inputArray, arrayIndex, synonymLength - wordLength);  // Accounts for synonym being bigger or smaller than original.
	// Put synonym into input array.
	for (int i = 0; i < synonymLength; i++)
		*(inputArray + arrayIndex + i - wordLength) = *(newWord + i);
	// current index of paragraph is updated with line, so that replaced word is not counted again.
	arrayIndex += synonymLength - wordLength;  
	cout << "\n\"" << word << "\" replaced with \"" << newWord << "\" successfully!\n\n";
}

void adjust_Sentence(char*& inputArray, int& arrayIndex, int factor)
{
	if (factor > 0)  // Synonym > current word.
	{   // Cycle input array forward(right) to accomodate bigger word. 
		for (int i = countArray(inputArray); i >= arrayIndex; i--)
			*(inputArray + i + factor) = *(inputArray + i);
	}
	else if (factor < 0)  // Synonym < current word.
	{   // Cycle input array backward(left) to accomodate smaller word.
		for (int i = arrayIndex + factor; *(inputArray + i - 1) != '\0'; i++)
			*(inputArray + i) = *(inputArray + i - factor);
	}
}

void delete_2DArray(char**& arr, const int& rows)
{
	if (arr)
	{
		for (int i = 0; i < rows; i++)
			delete[] * (arr + i);
		delete[] arr;
		arr = nullptr;
	}
}

void delete_3DArray(char***& arr, const int& rows, int*& columns)
{
	if (arr)  // if array exists.
	{
		for (int i = 0; i < rows; i++)
		{
			if (*(arr + i) != nullptr) // if synonym(s) exist.
			{  
				for (int j = 0; j < *(columns + i); j++)  // synonym count specifies how many char arrays there are.
					delete[] * (*(arr + i) + j);
				delete[] * (arr + i);
			}
		}
		delete[] arr;
		arr = nullptr;
	}
}