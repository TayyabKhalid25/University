#include <iostream>
using namespace std;

bool Exists(int data[][6],int pattern[][3])
{
	bool found;
	for (int i = 0; i < 6 - 3; i++) {  // 6 - 3 indicates that after this value, we cannot find array since search size(3x3) exceeds data limits.
		for (int j = 0; j < 6 - 3; j++) {  // (sizeof data - sizeof pattern)
			if (data[i][j] == pattern[0][0]) {
				found = true;
				for (int x = 0; x < 3; x++) {  // initiating search using x and y as index values
					for (int y = 0; y < 3; y++) {
						if (data[i + x][j + y] != pattern[x][y]) {
							found = false;
							break;  // if any wrong value, quit search of that column
						}
					}
					if (!found)  // if any wrong value, quit search of that area
						break;
				}
				if (found)  // quit function if found pattern within data
					return true;
			}
		}
	}
	return false;  // checked all possible combinations and not found
}

int main()
{
	int data[6][6] = { {1,2,7,8,9,6},
					  {2,2,3,4,5,6},
					  {3,2,3,4,5,6},
					  {4,2,3,4,5,6},
					  {5,2,9,8,7,6},
					  {6,2,7,4,5,6} };
	int pattern[3][3] = { {3,4,5},
						  {3,4,5},
						  {3,4,5}};
	cout << boolalpha << Exists(data, pattern) << endl;

	system("pause");
	return 0;
}