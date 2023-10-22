#include <iostream>
using namespace std;

int main() 
{
	// Part A:
	int d;
	cout << "Enter value of d: ";
	cin >> d;
	for(int i{0}; i < d; i++)
	{
		for(int j{i}; j < d; j++)
		{
			for(int k{j}; k < d; k++)
			{
				if (i * i + j * j + k * k == d)
					cout << i << "^2 + " << j << "^2 + " << k << "^2 = 1000\n";
			}
		}
	}
	// Part B:
	cout << "Enter new value of d: ";
	cin >> d;
	for (int i{ 0 }; i < d; i++)
	{
		for (int j{ i }; j < d; j++)
		{
			for (int k{ j }; k < d; k++)
			{
				if (i + j + k == d)
					cout << i << " + " << j << " + " << k << " = 1000\n";
			}
		}
	}

	return 0;
}