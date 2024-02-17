#include <iostream>
using namespace std;

int main()
{
	int size = 5;
	int* dynamicArray = new int[size];
	
	for (int i = 0; i < size; i++)
	{
		dynamicArray[i] = i * 2;
	
	}
	
	cout << "Array elements using pointer arithmetic:\n";
	
	for (int i = 0; i < size; i++)
	{
		cout << *(dynamicArray + i) << ' ';
	}
	
	
 	delete[] dynamicArray;
	cout << endl;
	system("pause");
	return 0;
}