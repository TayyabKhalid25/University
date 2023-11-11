#include <iostream>
using namespace std;

void Swap(int& num1, int& num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i+=2) {  //sorting even indexes in asc order
		int min = i;
		for (int j = i+2; j < size; j+=2) {
            if (arr[j] < arr[min])
                min = j;         
		}
        Swap(arr[min], arr[i]);
	}
    for (int i = 1; i < size - 1; i+=2) {  //sorting odd indexes in desc order
		int max = i;
		for (int j = i+2; j < size; j+=2) {
            if (arr[j] > arr[max])
                max = j;         
		}
        Swap(arr[max], arr[i]);
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
    cout << "Sorted Array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << ' ';
    cout << endl;

    return 0;
}