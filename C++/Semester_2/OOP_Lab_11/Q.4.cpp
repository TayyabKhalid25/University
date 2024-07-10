#include <iostream>

using namespace std;

class DivisionByZeroException : public exception {
    string msg;
public:
    DivisionByZeroException(string m = "Division by Zero") : msg(m) {}

    const char* what() const{
        return msg.c_str();
    }
};

class Fraction {
private:
    int num;
    int denom;

    int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    void simplify() {
        int commonDivisor = gcd(num, denom);
        num /= commonDivisor;
        denom /= commonDivisor;
    }

public:
    Fraction(int n = 0, int d = 0) : num(n), denom(d) {}

    void divide(const Fraction& other) {
        if (other.denom == 0) {
            throw DivisionByZeroException("Second Fraction's Denominator is 0\n");
        } else if (other.num == 0) {
            throw DivisionByZeroException();
        } else if (denom == 0) {
            throw DivisionByZeroException("First Fraction's Denominator is 0\n");
        }

        num *= other.denom;
        denom *= other.num;
        simplify();
    }

    void print() const {
        cout << num << "/" << denom;
    }
};

int main() {
    try {
        int num, denom;
        cout << "Enter Numerator and Denominator for 1st fraction: ";
        cin >> num >> denom;
        Fraction fraction1(num, denom);
        cout << "Enter Numerator and Denominator for 2nd fraction: ";
        cin >> num >> denom;
        Fraction fraction2(num, denom);

        cout << "Fraction 1: ";
        fraction1.print();
        cout << endl;

        cout << "Fraction 2: ";
        fraction2.print();
        cout << endl;

        fraction1.divide(fraction2);

        cout << "Result of division: ";
        fraction1.print();
        cout << endl;
    }
    catch (const DivisionByZeroException& e) {
        cout << "Error: " << e.what() << endl;
    }
    catch (...) {
        cout << "An unknown error occurred" << endl;
    }

    return 0;
}
