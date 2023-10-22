#include <iostream>
using namespace std;

int main() 
{
	int lcm, gcd, num1, num2, temp, a, b;
	cout << "Enter number 1: ";
	cin >> num1;
	cout << "Enter number 2: ";
	cin >> num2;
	a = num1;
	b = num2;
	// Finding GCD/HCF
	while (b != 0)
	{
		temp = b;
		b = a % b;
		a = temp;
	}
	gcd = a;
	// Finding LCM
	lcm = num1 * num2 / gcd;
	cout << "LCM is " << lcm << " and GCD is " << gcd << endl;
 
 return 0;
}