#include <iostream>
#include <random>

using namespace std;

class ArrayIndexOutOfBoundsException : public exception {
public:
    const char* printMessage() const{
        return "Array index out of bounds";
    }
};

class Arr {
private:
    int arr[5];
public:
    Arr() {
        random_device rn;
        for (int i = 0; i < 5; ++i) {
            arr[i] = rn() % 10000;
        }
    }

    int getElementAtIndex(int index) {
        if (index < 0 || index >= 5) {
            throw ArrayIndexOutOfBoundsException();
        }
        return arr[index];
    }
};

int main() {
    Arr array;

    try {
        cout << "Enter an index to retrieve value: ";
        int index;
        cin >> index;

        int value = array.getElementAtIndex(index);
        cout << "Value at index " << index << ": " << value << endl;
    }
    catch (const ArrayIndexOutOfBoundsException& e) {
        cout << "Error: " << e.printMessage() << endl;
    }
    catch (...) {
        cout << "An unknown error occurred" << endl;
    }

    return 0;
}
