#include <iostream>
using namespace std;

bool isPalindrome(int N)
{
    int orig = N, reverse = 0, digit;
    while (N > 0) {
        digit = N % 10;
        reverse = reverse * 10 + digit;
        N /= 10;
    }
    return (orig == reverse);
}

int main()
{
    int number;
    cout << "Enter a number: ";
    cin >> number;
    if (isPalindrome(number)) 
        cout << "It is a palindrome." << endl;
    else 
        std::cout << "It is not a palindrome." << endl;

	system("pause");
	return 0;
}