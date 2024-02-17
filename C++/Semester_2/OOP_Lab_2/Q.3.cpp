#include <iostream>
using namespace std;

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
		*(dynamicArray + i) += 5;
	}
	
	cout << "Modified array after incrementing elements by 5:\n";
	for (int i = 0; i < size; i++)
	{
		cout << *(dynamicArray + i) << ' ';
	}
	
	
 	delete[] dynamicArray;
	cout << endl;
	system("pause");
	return 0;
}