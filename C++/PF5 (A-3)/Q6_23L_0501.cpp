#include <iostream>
#include <iomanip>
using namespace std;

int Frequency(int arr[], int Us[], int Freq[], int size)
{
	int endpointer = 0;
	for (int i = 0; i < size; i++){  //seperating into distinct list
        bool found = false;
		for (int j = 0; j < endpointer; j++){
			if (arr[i] == Us[j]){
				found = true;
				break;
			}																						
		}
		if (!found){
			Us[endpointer] = arr[i];
			endpointer++;
		}
	}
    for (int i = 0; i < endpointer; i++){  //counting frequency
        int count = 0;
		for (int j = 0; j < size; j++){
			if (Us[i] == arr[j])
				count++;																					
		}
        Freq[i] = count;
    }
    return endpointer;
}

void Swap(int& num1, int & num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void sortFreq(int Us[], int Freq[], int size)
{
    for (int i = 0; i < size - 1; i++) {
		int max = i;
		for (int j = i+1; j < size; j++) {
            if (Freq[j] > Freq[max])
                max = j;         
		}
        Swap(Us[max], Us[i]);
        Swap(Freq[max], Freq[i]);
	}
}

void sortData(int arr[], int Us[], int Freq[], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++){
        for (int j = count; j < count + Freq[i]; j++){
            arr[j] = Us[i];
        }
        count += Freq[i];
    }
}

int main()
{
    int arr[30], Us[30], Freq[30], size = 0, endpointer, input;
    cout << "Input Array (Enter -99 to exit): ";
	for (int i = 0; i < 30; i++){
		cin >> input;
		if (input == -99)
			break;
		arr[i] = input;
        size++;
	}
    endpointer = Frequency(arr, Us, Freq, size);
    cout << "Us:          ";
    for (int i = 0; i < endpointer; i++)
        cout << setw(4) << Us[i];
    cout << "\nFreq:        ";
    for (int i = 0; i < endpointer; i++)
        cout << setw(4) << Freq[i];
    sortFreq(Us, Freq, endpointer);  //sort arrays
    cout << "\nSorted Us:   ";
    for (int i = 0; i < endpointer; i++)
        cout << setw(4) << Us[i];
    cout << "\nSorted Freq: ";
    for (int i = 0; i < endpointer; i++)
        cout << setw(4) << Freq[i];
    sortData(arr, Us, Freq, endpointer);  //sort data
    cout << "\nNew D Array: ";
    for (int i = 0; i < size; i++)
        cout << setw(4) << arr[i];
    cout << endl;


    return 0;
}