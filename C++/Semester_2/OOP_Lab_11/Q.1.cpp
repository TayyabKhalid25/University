#include <iostream>
using namespace std;

int main() {
	try{
		cout << "Enter 0 to throw exception int, 1 for throwing double, 2 for throwing string: ";
		int in;
		cin >> in;
		switch (in)
		{
		case 0:
			throw 0;
			break;
		
		case 1:
			throw 2.2;
			break;

		default:
			throw "sad boi hours\n";
			break;
		}
	}
	catch (int& a){
		cout << "Integer thrown.\n";
	}
	catch (double& a) {
		cout << "Double thrown.\n";
	}
	catch (...) {
		cout << "String thrown.\n";
	}


	return 0;
}
