#include <iostream>
using namespace std;

bool linearSearch(int arr[], int value)
{
	for (int i = 0; i < 10; i++)
	{
		if (arr[i] == value)
			return true;
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

	if (linearSearch(array, ticket) == true)
		cout << "Congratulations, you have won!!!\n";
	else
		cout << "You are not among the winners.\n";

	system("pause");
	return 0;
}