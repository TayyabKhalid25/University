#include <iostream>
using namespace std;

int main()
{
	int* dynamicInteger = new int;
	
	cout << "Enter integer value: ";
	cin >> *dynamicInteger;

	cout << "Value using dereference operator: " << *dynamicInteger << endl;
	cout << "Address of dynamic integer: " << &dynamicInteger << endl;
	

	delete dynamicInteger;
	system("pause");
	return 0;
}