#include <iostream>
using namespace std;

bool binarySearch(int arr[], int value)
{
	int start = 0, end = 9, mid;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (arr[mid] == value)
			return true;
		else if (value > arr[mid])
			start = mid + 1;
		else
			end = mid - 1;
	}
	return false;
}


int main()
{
	int array[10] = {13579, 26791, 26792, 33445, 55555, 62483, 77777, 79422, 85647, 93121};
	int ticket;
	do
	{
		cout << "Enter a valid 5-digit ticket number: ";
		cin >> ticket;
		if (ticket > 9999 && ticket < 100000)
			break;
	} while (true);
	if (binarySearch(array, ticket) == true)
		cout << "Congratulations, you have won!!!\n";
	else
		cout << "You are not among the winners.\n";

	system("pause");
	return 0;
}