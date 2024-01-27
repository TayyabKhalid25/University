//#include <iostream>
//using namespace std;
//
//int main() 
//{
//	int N, num[3], checktuple{ 0 };
//	cout << "Enter number N: ";
//	cin >> N;
//	if (N > 0) {
//		for (int i{ 1 }; i < N; i++)
//		{
//			if (i * (i + 1) * (i + 2) == N)
//			{
//				num[0] = i;
//				num[1] = i + 1;
//				num[2] = i + 2;
//				checktuple = 1; //3 tuples found flag
//				i = N; // Break out of loop
//			}
//		}
//		if (checktuple == 1)
//			cout << num[0] << " * " << num[1] << " * " << num[2] << " = " << N;
//		else
//			cout << "NO";
//	} else {
//		cout << "Invalid input.\n";
//	}
//	return 0;
//}