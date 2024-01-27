#include <iostream>
using namespace std;

void sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++) {  //sorting array in asc order
		int min = i;
		for (int j = i+1; j < size; j++) {
            if (arr[j] < arr[min])
                min = j;         
		}
		int temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
	}
    int temp[100];
    for (int i = 0; i < size; i++)  //creation of duplicate array
        temp[i] = arr[i];
    int i = 0, k = 0, j = size - 1;
    while (i<j){  //rearrangement of original array
        arr[k++] = temp[j--];
        arr[k++] = temp[i++];
    }
    if (size % 2 != 0) 
        arr[k] = temp[i];  
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
    cout << "Sorted Array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << ' ';
    cout << endl;

    return 0;
}