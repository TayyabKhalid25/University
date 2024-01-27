#include <iostream>
using namespace std;

int countinsertion = 0, countselection = 0;

void insertionSort(int arr[])
{
	int key, j;
	for (int i = 1; i < 20; i++) {
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
			countinsertion++;
		}
		arr[j + 1] = key;
	}
}

void selectionSort(int arr[]) 
{
	for (int i = 0; i < 19; i++) {
		int min = i;
		for (int j = i+1; j < 20; j++) {
			if (arr[j] < arr[min])
				min = j;
		}
		int temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
		countselection++;
	}
}

int main()
{
	int array1[20], array2[20], input;
	for (int i = 0; i < 20; i++)
	{
		cout << "Enter number to be put in array: ";
		cin >> input;
		array1[i] = input;
	}
	for (int i = 0; i < 20; i++)
		array2[i] = array1[i];
	insertionSort(array1);
	selectionSort(array2);
	cout << "Count of swaps in insertion sort is: " << countinsertion << endl;
	cout << "Count of swaps in selection sort is: " << countselection << endl;
	cout << "Array sorted by insertion sort:\n";
	for (int i = 0; i < 20; i++)
		cout << array1[i] << ' ';
	cout << "\nArray sorted by selection sort:\n";
	for (int i = 0; i < 20; i++)
		cout << array2[i] << ' ';
	cout << endl;

	system("pause");
	return 0;
}