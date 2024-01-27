//#include <iostream>
//using namespace std;
//
//int main() 
//{
//	// Part A:
//	int d;
//	cout << "Enter value of d: ";
//	cin >> d;
//	for(int i{0}; i < d; i++)
//	{
//		for(int j{i}; j < d; j++)
//		{
//			for(int k{j}; k < d; k++)
//			{
//				if (i * i + j * j + k * k == d)
//					cout << i << "^2 + " << j << "^2 + " << k << "^2 = " << d << endl;
//			}
//		}
//	}
//	// Part B:
//	cout << "Enter new value of d: ";
//	cin >> d;
//	for (int i{ 0 }; i < d; i++)
//	{
//		for (int j{ i }; j < d; j++)
//		{
//			for (int k{ j }; k < d; k++)
//			{
//				if (i + j + k == d)
//					cout << i << " + " << j << " + " << k << " = " << d << endl;
//			}
//		}
//	}
//
//	return 0;
//}