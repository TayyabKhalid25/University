#include <iostream>
using namespace std;

int main() 
{
	int input{ 0 }, even{ 0 }, odd{ 0 };
	while (input != -1)
	{
		cout << "Enter positive number as input: ";
		cin >> input;
		if (input > 0){
			if (input % 2 == 0)
				even += 1;
			else
				odd += 1;
		} else if (input != -1)
			cout << "Wrong input.\n";
	}
	cout << "The frequency of even numbers entered is: " << even << endl;
	cout << "The frequency of odd numbers entered is: " << odd << endl;

	return 0;
}