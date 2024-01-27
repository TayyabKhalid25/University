#include <iostream>
using namespace std;

double CalculateGPA(char g1, int c1, char g2, int c2, char g3, int c3, char g4, int c4, char g5, int c5)
{
	double gpa = 0;
		switch (g1)
		{
		case 'A':
			gpa += 4 * c1;
			break;
		case 'B':
			gpa += 3 * c1;
			break;
		case 'C':
			gpa += 2 * c1;
			break;
		case 'D':
			gpa += 1 * c1;
			break;
		case 'F':
			gpa += 0;
			break;
		}
		switch (g2)
		{
		case 'A':
			gpa += 4 * c2;
			break;
		case 'B':
			gpa += 3 * c2;
			break;
		case 'C':
			gpa += 2 * c2;
			break;
		case 'D':
			gpa += 1 * c2;
			break;
		case 'F':
			gpa += 0;
			break;
		}
		switch (g3)
		{
		case 'A':
			gpa += 4 * c3;
			break;
		case 'B':
			gpa += 3 * c3;
			break;
		case 'C':
			gpa += 2 * c3;
			break;
		case 'D':
			gpa += 1 * c3;
			break;
		case 'F':
			gpa += 0;
			break;
		}
		switch (g4)
		{
		case 'A':
			gpa += 4 * c4;
			break;
		case 'B':
			gpa += 3 * c4;
			break;
		case 'C':
			gpa += 2 * c4;
			break;
		case 'D':
			gpa += 1 * c4;
			break;
		case 'F':
			gpa += 0;
			break;
		}
		switch (g5)
		{
		case 'A':
			gpa += 4 * c5;
			break;
		case 'B':
			gpa += 3 * c5;
			break;
		case 'C':
			gpa += 2 * c5;
			break;
		case 'D':
			gpa += 1 * c5;
			break;
		case 'F':
			gpa += 0;
			break;
		}
		gpa /= c1 + c2 + c3 + c4 + c5;
		return gpa;
}

int main()
{
	double GPA = CalculateGPA('A', 3, 'B', 3, 'B', 3, 'C', 2, 'A', 1);		
	cout << "My gpa is: " << GPA << endl;

	system("pause");
	return 0;
}