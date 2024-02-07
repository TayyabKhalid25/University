#include <iostream>
using namespace std;

void reverseArray(int* arr, int size)
{
	for (int i = 0; i < size / 2; i++)
	{
		int temp = *(arr + i);
		*(arr + i) = *(arr + size - 1 - i);
		*(arr + size - 1 - i) = temp;
	}
}

int main()
{
	int size;
	cout << "Enter size of array: ";
	cin >> size;

	int* dynamicArray = new int[size];

	cout << "Enter " << size << " integers for the array:\n";
	for (int i = 0; i < size; i++)
	{
		cout << "Element " << i + 1 << ": ";
		cin >> dynamicArray[i];
	}

	reverseArray(dynamicArray, size);

	cout << "The reversed array is:\n";
	for (int i = 0; i < size; i++)
	{
		cout << *(dynamicArray + i) << ' ';
	}


	delete[] dynamicArray;
	cout << endl;
	system("pause");
	return 0;
}