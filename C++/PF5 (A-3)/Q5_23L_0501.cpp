#include <iostream>
using namespace std;

int main()
{
    int arr[100], endpointer = 0, input, element, index;
    cout << "Enter the Array. Enter -1 to exit: ";
	for (int i = 0; i < 100; i++){
		cin >> input;
		if (input == -1)
			break;
		arr[i] = input;
        endpointer++;
	}
    cout << "Enter the element to be added: ";
    cin >> element;
    cout << "Enter the index where the element is to be added: ";
    cin >> index;
    if (index < 0 || index > endpointer - 1){
        cout << "Wrong index entered.";
        return 0;
    }
    for(int i = endpointer; i >= index; i--)  //shift array to right
        arr[i]= arr[i-1];
    arr[index] = element;
    endpointer++;
    for(int i = 0; i < endpointer; i++)  //print array
        cout << arr[i] << ' ';
    cout << endl;

    return 0;
}