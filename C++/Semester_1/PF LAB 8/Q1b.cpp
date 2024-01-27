#include <iostream>
using namespace std;

void cycleRotate(int arr[], int d)
{
	if (d > 0)
	{
		int temp;
		temp = arr[0];
		for (int i = 0; i < 9; i++)
			arr[i] = arr[i + 1];
		arr[9] = temp;
		cycleRotate(arr, d - 1);
	}
	else if (d < 0)
	{
		int temp;
		temp = arr[9];
		for (int i = 9; i > 0; i--)
			arr[i] = arr[i-1];
		arr[0] = temp;
		cycleRotate(arr, d + 1);
	}
}

int main()
{
	int array[10], input, d;
	for (int i = 0; i < 10; i++)
	{
		cout << "Enter number to be put in array holding 10 integers:";
		cin >> input;
		array[i] = input;
	}
	cout << "Enter factor d to rotate left by:";
	cin >> d;
	cycleRotate(array, d);
	for (int i = 0; i < 10; i++)
		cout << array[i] << ' ';

	system("pause");
	return 0;
}