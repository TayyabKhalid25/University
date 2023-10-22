#include <iostream>
using namespace std;

int main() 
{
	// Part I:
	int k_Fibonacci, k, a{ 0 }, b{ 1 }, Fibonacci{ 0 }, temp;
	cout << "How many Fibonacci Numbers you want to ask?: ";
	cin >> k_Fibonacci;
	if (k_Fibonacci > 0) {
		for (int i{ 0 }; i < k_Fibonacci; i++)
		{
			if (i == 0)
				cout << "Which Fibonacci: ";
			else if (i == k_Fibonacci - 1)
				cout << "Which last Fibonacci you want to ask is: ";
			else
				cout << "Which Next Fibonacci: ";
			cin >> k;
			if (k < 0) {
				cout << "Wrong value entered:\n";
				i--;
			} else {
				if (k == 0)
					Fibonacci = 0;
				else if (k == 1)
					Fibonacci = 1;
				for (int j{ 1 }; j < k; j++)
				{
					Fibonacci = temp = a + b;
					a = b;
					b = temp;
				}
				cout << 'F' << k << " = " << Fibonacci << endl;
				a = 0;
				b = 1;
			}
		}
	} else
		cout << "Wrong value entered.\n";
	// Part II:
	int T;
	cout << "You want to print upto: ";
	cin >> T;
	if (T > 0) {
		cout << "The sequence upto " << T << " is: ";
		if (T >= 0)
			cout << "0, ";
		if (T >= 1)
			cout << "1, ";
		a = 0, b = 1;
		while (Fibonacci <= T) {
			Fibonacci = temp = a + b;
			a = b;
			b = temp;
				if (Fibonacci <= T)
					std::cout << Fibonacci << ", ";
		} 
	}
	else
		cout << "Wrong value entered.\n";
	cout << endl;
	//Part III:
	int start, end;
	cout << "Enter Start value: ";
	cin >> start;
	cout << "Enter End value: ";
	cin >> end;
	if (start > 0 && end > 0) {
		cout << "The fibonacci numbers between them are: ";
		if (start == 0)
			cout << "0, ";
		if (start == 1)
			cout << "1, ";
		a = 0, b = 1;
		while (Fibonacci <= end) {
			Fibonacci = temp = a + b;
			a = b;
			b = temp;
				if (Fibonacci <= end && Fibonacci >= start)
					std::cout << Fibonacci << ", ";
		} 
	}
	else
		cout << "Wrong value entered.\n";
	cout << endl;
	//Part IV:
	int sum{0};
	a = 0, b = 1;
	while (Fibonacci <= 4000000) {
		Fibonacci = temp = a + b;
		if (Fibonacci % 2 == 0)
			sum += Fibonacci;
		a = b;
		b = temp;
	}
	cout << "Sum of even values till 4 million is: " << sum << endl;

	return 0;
}