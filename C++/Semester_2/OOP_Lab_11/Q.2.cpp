#include <iostream>
#include <cmath>
using namespace std;


double add(double a, double b) {
    if (isnan(a) || isnan(b)) {
        throw invalid_argument("One or both arguments are non-numeric.");
    }
    return a + b;
}

int main() {
    try {
        double result = add(5.5, 10.3);
        cout << "Result: " << result << endl;

        // Testing with non-numeric argument
        result = add(5.5, NAN);
        cout << "Result: " << result << endl; // test to see if exception thrown
    }
    catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}
