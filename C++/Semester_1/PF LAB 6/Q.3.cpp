#include <iostream>
#define pi 3.14159;
using namespace std;

double area(double radius)
{
	return radius*radius*pi;
}


int main()
{
	double r;
	cout << "Enter radius of circle: ";
	cin >> r;
	cout << "Area of circle is: " << area(r) << endl;
	
	system("pause");
	return 0;
}