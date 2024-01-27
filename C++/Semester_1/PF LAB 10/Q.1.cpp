#include <iostream>
using namespace std;

const int Size = 100;
int arr_size;

int Trace(int data[][Size]) 
{
    int sum = 0;
    for (int i = 0; i < arr_size; i++) {  // Output of matrix
        sum += data[i][i];
    }
    return sum;
}

int main()
{
	cout << "Enter size of row/column of square matrix: ";
	cin >> arr_size;
    int arr[Size][Size];
    for (int i = 0; i < arr_size; i++) {  // Getting user input for array
        for (int j = 0; j < arr_size; j++) {
            cout << "Enter [" << i << "] [" << j << "] value: ";
            cin >> arr[i][j];
        }
    }
    cout << "\nThe given matrix is:\n";
    for (int i = 0; i < arr_size; i++) {  // Output of matrix
        for (int j = 0; j < arr_size; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << "\nSum of diagonals is: " << Trace(arr) << endl;

	system("pause");
	return 0;
}