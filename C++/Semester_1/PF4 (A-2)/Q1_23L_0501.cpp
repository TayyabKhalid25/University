//#include <iostream>
//using namespace std;
//
//int main() 
//{
//	int lcm, gcd, num1, num2, temp, a, b;
//	do{
//		cout << "Enter number 1: ";
//		cin >> num1;
//		cout << "Enter number 2: ";
//		cin >> num2;
//		if (num1 <= 0 || num2 <= 0)
//			cout << "Invalid numbers entered.\n";
//	} while (num1 <= 0 || num2 <= 0);
//	a = num1;
//	b = num2;
//	// Finding GCD/HCF
//	while (b != 0)
//	{
//		temp = b;
//		b = a % b;
//		a = temp;
//	}
//	gcd = a;
//	// Finding LCM
//	lcm = num1 * num2 / gcd;
//	cout << "LCM is " << lcm << " and GCD is " << gcd << endl;
// 
// return 0;
//}