#include <iostream>
using namespace std;

void sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++) {
		int min = i;
		for (int j = i+1; j < size; j++) {
            if (arr[j] < arr[min])
                min = j;         
		}
		int temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
	}
}

int main()
{
    int arr[100], input, size = 0;
	cout << "Enter the Array. Enter -1 to exit: ";
	for (int i = 0; i < 100; i++){
		cin >> input;
		if (input == -1)
			break;
		arr[i] = input;
        size++;
	}
    sort(arr, size);
    cout << "Segregated Array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << ' ';
    cout << endl;

    return 0;
}