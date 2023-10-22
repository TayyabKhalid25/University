#include <iostream>
using namespace std;

void FindMinMax(int& minValue, int& maxValue) {  // Passing two values by reference.
    int input;
    bool firstInput = true;
    cout << "Enter integers (enter -1 to stop):\n";
    while (true) {
        cin >> input;
        if (input == -1) {
            if (firstInput) {
                cout << "No valid input provided." << endl;
                return;
            }
            break;
        }
        if (firstInput) {
            minValue = maxValue = input;
            firstInput = false;
        }
        else {
            if (input < minValue) {
                minValue = input;
            }
            if (input > maxValue) {
                maxValue = input;
            }
        }
    }
}


int main()
{
    int min{ 0 }, max{ 0 };
    FindMinMax(min, max);
    cout << "Minimum is " << min << " and maximum is " << max << endl;


	system("pause");
	return 0;
}