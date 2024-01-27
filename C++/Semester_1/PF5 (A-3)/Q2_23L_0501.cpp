#include <iostream>
using namespace std;

void sort(int arr[], int size, char option)
{
    for (int i = 0; i < size - 1; i++) {
		int endpoint = i;
		for (int j = i+1; j < size; j++) {
            if (option == 'a'){  //ascending
            	if (arr[j] < arr[endpoint])
			    	endpoint = j;
            }else if (option == 'd'){  //descending
            	if (arr[j] > arr[endpoint])
			    	endpoint = j;
            }
		}
		int temp = arr[endpoint];
		arr[endpoint] = arr[i];
		arr[i] = temp;
	}
}

void identifyDistinct(int arr[], int size)
{
	int distinct[20], endpointer = 0;
	for (int i = 0; i < size; i++){
		bool found = false;
		for (int j = 0; j < endpointer; j++){
			if (arr[i] == distinct[j]){
				found = true;
				break;
			}																						
		}
		if (!found){
			distinct[endpointer] = arr[i];
			endpointer++;
		}
	}
    sort(distinct, endpointer, 'a');
	cout << "Distinct Elements in Sorted (Increasing order) are: ";
	for (int i = 0; i < endpointer; i++)
		cout << distinct[i] << ' ';
	cout << endl;
}

void identifyUnique(int arr[], int size)
{
	int unique[20], endpointer = 0;
	for (int i = 0; i < size; i++){
		bool found = false;
		for (int j = 0; j < size; j++){
			if (arr[i] == arr[j] && i != j){
				found = true;
				break;
			}																						
		}
		if (!found){
			unique[endpointer] = arr[i];
			endpointer++;
		}
	}
    sort(unique, endpointer, 'd');
	cout << "Unique Elements in Sorted (Decreasing order) are: ";
	for (int i = 0; i < endpointer; i++)
		cout << unique[i] << ' ';
	cout << endl;
}


int main()
{
    int arr[20], input, size = 0;
	cout << "Enter numbers to be put in array(Enter -99 to exit): ";
	for (int i = 0; i < 20; i++){
		cin >> input;
		if (input == -99)
			break;
		arr[i] = input;
        size++;
	}
    identifyDistinct(arr, size);
    identifyUnique(arr, size);
    
    return 0;
}