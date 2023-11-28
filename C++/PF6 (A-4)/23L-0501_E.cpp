// Name: Tayyab Khalid
// Roll Num: 23L-0501 
// Section: BCS-1E1
// Assignment 4
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

bool imperfect_palindrome(char word[])
{
	//  when reading an imperfect palindrome forward and backward, the number of characters that differ is no more then 2

	int endp = 0, freq_difference = 0;
	while (word[endp] != '\0')  // finds the index where word ends
		endp++;
	for (int i = 0; i < endp / 2; i++) {
		if (word[i] != word[endp - 1 - i])
			freq_difference++;
	}
	if (freq_difference == 1)  // if 1, it means not a perfect palindrome and exactly 1 pair (2 characters) are different 
		return true;
	return false;  //else return false
}

bool distinct_match_form(char word[], int& endp, bool match, int distinct[20])
{
	for (int i = 0; word[i] != '\0'; i++) {  // code for finding all letters used in word 1 (distinct array)
		bool found = false;
		for (int j = 0; j < endp; j++) {  // check distinct array if letter already exists
			if (word[i] == distinct[j]) {
				found = true;
				break;
			}
		}
		if (!found && !match)  // match indicates whether we want to check with existing distinct array or make a new one
			distinct[endp++] = word[i];  // update distinct array and its pointer
		else if (!found && match)
			return false;  // return false to indicate that word and distinct array do not match
		i++;
	}
	return true;
}

bool super_anagrams(char word1[], char word2[])
{
	// 1. that consist of the same letters. 
	// 2. that the accumulated frequency difference of the letters in the pair of words differs atmost 2
	
	int distinct[20], endpointer = 0, freq_difference = 0;
	distinct_match_form(word1, endpointer, false, distinct);  // forms the distinct array (All letters of word 1)
	bool anagram = distinct_match_form(word2, endpointer, true, distinct);  // checks whether word 2 letters are same as word 1
	if (anagram){  // check frequency difference
		int count[128] = { 0 };  // there are 128 ascii codes normally, initialise array with 0
		for (int i = 0; word1[i] != '\0'; i++)
			count[word1[i]]++;  // letter index incremented in word 1
		for (int i = 0; word2[i] != '\0'; i++)
			count[word2[i]]--;  // letter indec decremented in word 2, if same freq, should be back to 0
		for (int i = 0; i < 256; i++)
			if (count[i] != 0)
				freq_difference += abs(count[i]);  // adds the amount of letters which are not the same
		if (freq_difference > 2)
			anagram = false;
	}
	return anagram;
}

void seperate_words(char seperate[], char word1[], char word2[])
{
	int count = 0, i = 0;
	while (seperate[count] != ' ')   // finds the index of space b/w words as well as forms the first word
		word1[count] = seperate[count++];
	word1[count++] = '\0';  // index points to first letter of next word now nd null pointer used to end word
	while (seperate[count] != ' ' && seperate[count] != '\0') 
		word2[i++] = seperate[count++];  // Formation of second word
	word2[i] = '\0';  // null pointer to end word
}

int main()
{
	char Input[41], word1[20], word2[20];
	ifstream in("InputFile.txt");
	cout << "Word 1 Imperfect Palindrome Check:\tWord 2 Imperfect Palindrome Check:\tSuper-Anagrams Check:\n";
	while (!in.eof())  // loop runs till end of file
	{
		in.getline(Input, 41);
		seperate_words(Input, word1, word2);
		cout << Input << ":\n\n" << left;
		cout << setw(40) << (imperfect_palindrome(word1) == 1 ? "Yes" : "No");
		cout << setw(40) << (imperfect_palindrome(word2) == 1 ? "Yes " : "No ");
		cout << (super_anagrams(word1, word2) == 1 ? "Yes\n\n" : "No\n\n");
	}
	in.close();

	return 0;
}