#include <iostream>
using namespace std;

const int N = 5;

void Upper_half(int A[N][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {  // spaces before print
			cout << ' ';
		}
		for (int j = i; j < N; j++) {  // print row
			cout << A[i][j];
		}
		cout << '\n';
	}
}

int main()
{
	int arr[N][N] = { {2,3,1,5,0},
					  {7,1,5,3,1},
					  {2,5,7,8,1},
					  {0,1,5,0,1},
					  {3,4,9,1,5} };
	Upper_half(arr);

	system("pause");
	return 0;
}