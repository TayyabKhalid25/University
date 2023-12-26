#include <iostream>
#include "operations.h"  // Preprocessor where function incr_mult is declared. It is defined in operations.cpp, which will compile with Main.cpp
// Header file can also include the definition.
using namespace std;

// Function that doesn't return a result explicitly. (Procedure)
void enter_bar() 
{
    cout << "Enter age: ";
    int age;
    cin >> age;
    if (age > 18) 
        std::cout << "You're " << age << " years old. Please proceed." << std::endl; 
    else 
        std::cout << "Sorry, you're too young for this. No offense! " << std::endl;
}

// Function that takes multiple parameters and returns the result of the computation
int max(int a, int b)  // parameters go here, default is pass by value.
{
    if (a > b)
        return a;
    else
        return b;
}  // if no value returned for non void functions, compile error, which wont be highlighted usually.

// Function declaration, definition can be given anywhere in file. 
int min(int a, int b);  

// Parameters can also be passed as const values, which ensures they dont get changed during function running.
// Parameters can be passed by reference by using & symbol between data type and variable name. e.g int &number
// Parameters can be passed by const reference as well as by pointer. e.g const int &number, int *number 

double sum(double scores[], int count)  // u can specify size of array parameter, or leave it blank.
{  // all arrays are passed by reference by default.
    double score_sum{};
    for (int i = 0; i < count; i++) {  // std::size can be used, but sad(N/A in uni).
        score_sum += scores[i];
    }
    return score_sum;
}

double sum(double scores[][5])  // for any multi-dimensional array, you have to specify the number of elements in []'s, only the left most is not mandatory.
{
    double score_sum{};
    for (int i = 0; i < 5; i++) {  // std::size can be used here as well, but sad(N/A in uni).
        for (int j = 0; j < 5; j++)
            score_sum += scores[i][j];
    }
    return score_sum;
}

double sum_3d(const double array[][3][2], int size) {

    double sum{};
    for (int i{}; i < size; ++i) // Loop through rows, only number of rows can be kept undefined and hence variable.
    {
        for (int j{}; j < 3; ++j) // Loop through elements in a row
        {
            for (int k{}; k < 2; ++k) 
                sum += array[i][j][k];
        }
    }
    return sum;
}

int main()
{
    incr_mult(20, 30);  
    double my_scores[]{ 10.5,34.3,4.8,6.5 };
    int length = sizeof(my_scores) / sizeof(my_scores[0]);
    cout << "result : " << sum(my_scores, length) << endl;  // normally, length of array cannot be calculated using sizeof inside function.

	return 0;
}

// Function definition. Shows up after main 
int min(int a, int b) 
{
    if (a < b)
        return a;
    else
        return b;
}
