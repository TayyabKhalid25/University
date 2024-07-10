#include <iostream>
using namespace std;

// Operator Overloading examples:
class Complex {
private:
    double real;
    double imag;

public:
    // Constructor
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Overload the assignment operator (=)
    Complex& operator=(const Complex& c) {
        if (this != &c) { // Self-assignment check
            real = c.real;
            imag = c.imag;
        }
        return *this;
    }

    // Overload the + operator
    Complex operator+(const Complex& c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    // Overload the - operator
    Complex operator-(const Complex& c) const {
        return Complex(real - c.real, imag - c.imag);
    }

    // Overload the * operator
    Complex operator*(const Complex& c) const {
        return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
    }

    // Overload the / operator
    Complex operator/(const Complex& c) const {
        double denominator = c.real * c.real + c.imag * c.imag;
        return Complex((real * c.real + imag * c.imag) / denominator,
            (imag * c.real - real * c.imag) / denominator);
    }

    // Overload the == operator
    bool operator==(const Complex& c) const {
        return real == c.real && imag == c.imag;
    }

    // Overload the != operator
    bool operator!=(const Complex& c) const {
        return !(*this == c);
    }

    // Overload the > operator
    bool operator>(const Complex& c) const {
        return (real * real + imag * imag) > (c.real * c.real + c.imag * c.imag);
    }

    // Overload the < operator
    bool operator<(const Complex& c) const {
        return (real * real + imag * imag) < (c.real * c.real + c.imag * c.imag);
    }

    // Overload the >= operator
    bool operator>=(const Complex& c) const {
        return (real * real + imag * imag) >= (c.real * c.real + c.imag * c.imag);
    }

    // Overload the <= operator
    bool operator<=(const Complex& c) const {
        return (real * real + imag * imag) <= (c.real * c.real + c.imag * c.imag);
    }

    // Overload the [] operator
    double& operator[](int index) {
        if (index == 0) return real;
        else if (index == 1) return imag;
        else throw out_of_range("Index out of range");
    }

    const double& operator[](int index) const {
        if (index == 0) return real;
        else if (index == 1) return imag;
        else throw out_of_range("Index out of range");
    }

    // The following two operators can also be made a global function without friend keyword to achieve the same funtion.
    // Overload the << operator for output
    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real << " + " << c.imag << "i";
        return out;
    }

    // Overload the >> operator for input
    friend istream& operator>>(istream& in, Complex& c) {
        cout << "Enter real part: ";
        in >> c.real;
        cout << "Enter imaginary part: ";
        in >> c.imag;
        return in;
    }

    // Overload the prefix ++ operator
    Complex& operator++() {
        ++real;
        ++imag;
        return *this;
    }

    // Overload the postfix ++ operator
    Complex operator++(int) {
        Complex temp = *this;
        ++(*this);
        return temp;
    }

    // Overload the prefix -- operator
    Complex& operator--() {
        --real;
        --imag;
        return *this;
    }

    // Overload the postfix -- operator
    Complex operator--(int) {
        Complex temp = *this;
        --(*this);
        return temp;
    }
};

// Static Keyword and its Functionality:

void counter() {
    static int count = 0; // This variable retains its value between function calls
    count++;
    cout << "Count: " << count << endl;
}

//int main() {
//    counter(); // Count: 1
//    counter(); // Count: 2
//    counter(); // Count: 3
//    return 0;
//}

class Example {
public:
    static int count; // A static member variable of a class is shared among all instances of the class.

    static void displayCount() {  // A static member function of a class can be called without an instance of the class. 
        cout << "Count: " << count << endl;
    }

    Example() {
        count++;
    }
};

int Example::count = 0; // Definition of static member variable outside class is required.

//int main() {
//    Example::displayCount(); // Output: Count: 0
//    Example obj1;
//    Example obj2;
//    Example obj3;
//
//    cout << "Number of objects created: " << Example::count << endl; // Output: 3
//    return 0;
//}