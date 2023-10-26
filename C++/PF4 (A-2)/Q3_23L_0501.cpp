//#include <iostream>
//using namespace std;
//
//int main() 
//{
//	int number{ 0 }, checkroot{0}, squarenum;
//	while (number != -1) 
//	{
//		cout << "Enter a number to know is a perfect square: ";
//		cin >> number;
//		if (number > 0) {
//			for(int i{0}; i < number; i++)
//			{
//				if (i * i == number) {
//					checkroot = 1;
//					squarenum = i; 
//					i = number;
//				}
//			}
//			if (checkroot == 1) {
//				cout << " The number is a perfect square of " << squarenum << ".\n";
//				checkroot = 0;
//			} else {
//				cout << " The number is not a perfect square.\n";
//			}
//		}else if (number != -1)
//			cout << " Wrong input.\n";
//	}
//
// return 0;
//}