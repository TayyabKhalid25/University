#include <iostream>
using namespace std;

float calculator(float a, float b, char c)
{
	switch (c)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		return a / b;
	case '%':
		return (int)a % (int)b;
	case '^':
		int value = 1;
		for (int i = 0; i < b; i++)
		{
			value *= a;
		}
		return value;
	}
}

int main() 
{
	float op1, op2;
	char option = '+';
	cout << "Welcome to the Calculator!\nEnter\n+ for addition operation\n- for subtraction operation\n* for multiplication operation\n/ for division operation\n% for modulus operation\n^ for exponentiation operation\nq to quit\n";
	while (true)
	{
		cout << "\n-->";
		cin >> option;
		if (option == 'q' || option == 'Q')
			break;
		else {
			cout << "Enter the first operand: ";
			cin >> op1;
			cout << "Enter the second operand: ";
			cin >> op2;
			cout << "\nThe result is " << calculator(op1, op2, option) << endl;
		}		
	}

	system("pause");
	return 0;
}