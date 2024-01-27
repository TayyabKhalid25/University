#include <iostream>
#include "operations.h"  // Preprocessor where function incr_mult is declared. It is defined in operations.cpp,
// which will compile with Main.cpp
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

// Overloading function requires that parameter list be different, only different return type wont work.
double max(double a, double b)  
{
    if (a > b)
        return a;
    else
        return b;
}
double max(int a, double b)  // This will also work.
{
    if (a > b)
        return a;
    else
        return b;
}

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

double sum(double scores[][5])  // for any multi-dimensional array, you have to specify the number of elements in []'s,
// only the left most is not mandatory.
{
    double score_sum{};
    for (int i = 0; i < 5; i++) {  // std::size can be used here as well, but sad(N/A in uni).
        for (int j = 0; j < 5; j++)
            score_sum += scores[i][j];
    }
    return score_sum;
}

double sum_3d(const double array[][3][2], int size) 
{

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

// Function Templates are used when there are multiple data types that can be used in the same function. The various types are not 
// generated until you call the function using the data type, effectively saving space.
template <typename T> T maximum(T a, T b)
{
    return (a > b) ? a : b;  // Templates can only be used for data types that support comparison (<,>...) operations.
}
template <typename T, typename W> T maximum(T &a, W &b)  // This format can also be used for multiple different types, although
// not recommended
{
    return (a > b) ? a : b;  
}
// cout << maximum(a, b); // compiler error since different data types.
// cout << maximum<double>(a, b);  // if you want to use different data types in the same template, explicitly provide the data type
// that all variables will be implicitly converted to so that the function can work.

template<> const char* maximum<const char*>(const char* a, const char* b)  // Template specialization can be used to include certain 
// exceptions to the template, e.g char* cant be compared using operator, so strcmp is used instead.
{
    return (strcmp(a, b) > 0) ? a : b;
}  // Further template concepts come in c++20, not discussed here.

int main()
{
    incr_mult(20, 30);  
    double my_scores[]{ 10.5,34.3,4.8,6.5 };
    int length = sizeof(my_scores) / sizeof(my_scores[0]);
    cout << "result : " << sum(my_scores, length) << endl;  // normally, length of array cannot be calculated using sizeof inside
    // function.
    int a = 20;
    double b = 2.0;

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
