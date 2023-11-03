#include <iostream>
using namespace std;

void printUnique(int arr[])
{
	int unique[100], endpointer = 0;
	for (int i = 0; i < 100; i++)
	{
		bool found = false;
		for (int j = 0; j < 100; j++)
		{
			if (arr[i] == arr[j] && i != j)
			{
				found = true;
				break;
			}																						
		}
		if (!found)
		{
			unique[endpointer] = arr[i];
			endpointer++;
		}
	}
	cout << "Unique elements in the array are: ";
	for (int i = 0; i < endpointer; i++)
		cout << unique[i] << ' ';
	cout << endl;
}


int main()
{
	int array[100], input;
	for (int i = 0; i < 100; i++)
	{
		cout << "Enter number to be put in array(Enter -1 to exit):";
		cin >> input;
		if (input == -1)
			break;
		array[i] = input;
	}
	printUnique(array);

	system("pause");
	return 0;
}