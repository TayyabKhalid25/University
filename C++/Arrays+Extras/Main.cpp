#include <iostream>
#include <random>
using namespace std;

int main()
{
    // Random Number Generator:
    srand(time(0));  // srand sets the seed of the rand function. time gives it the current system time, which makes it unique everytime.
    cout << rand() << endl; // gives us random number till RAND_MAX, approximately max num of int.
    cout << RAND_MAX << endl;  // 32767 in my laptop
    cout << rand() % 6 << endl;  // gives us random number from 0 to 5
    cout << (rand() % 6) + 1 << endl;  // gives us random number from 0 to 6
    // Alternative:
    random_device rn;  // uses <random> library, does not have srand limitations and creates an object. Similar to rand()
    cout << rn()  << endl;  // gives us random number till rn.max(), approximately max num of double.
    cout << rn.max() << endl;  // 4294967295 in my laptop
    cout << rn() % 6 << endl;  // gives us random number from 0 to 5
    cout << (rn() % 6) + 1 << endl;  // gives us random number from 0 to 6
    
    // 1D Arrays:
    int scores[10];  // square brackets used for arrays. arrays start from 0. [10] means 0 - 9, meaning 10 total elements. diff from python.
    int arr[10]{ 0 };
    int arr1[10] = { 0 };  // This and above one will initialise all elements with 0.
    int salary[]{ 1,2,5,11,13,15 }; // u can initialise array with elements, and can also omit size. 
    int families[5]{ 2,2,1 }; // no need to put values in all elements.
    // Range based For Loop using array:
    int sum{ 0 };
    for (int element : salary) 
        sum += element;  // sum will be calculated of all the elements in the array, Range Based For Loop.
    cout << size(arr) << endl;  // std::size(array) will output total elements of array.(C++17 onwards)
    cout << sizeof(arr) / sizeof(arr[0]) << endl;  // Before C++17, this would be used.
    
    // CStrings:
    char message[5]{ 'H','e','l','l','o' };  // exactly 5 letters in hello
    char message2[6]{ 'H','e','l','l','o' };  // if done by omitting size, no null character will be at end of array. 
    cout << message << endl;  // will print hello, but with garbage characters since no null value was found at the end of array.
    cout << message2 << endl;  // will print hello normally since a null value was at end of array. Null value is \0.
    char message3[]{ "Hello World!" };
    cout << message3 << endl;  //initialising with a string and omitting size will give it a null terminator at the end of array.
    // can't print arrays other than char datatype using the same methods.
    // Common check functions:
    // isalnum (alphanumeric), isalpha (alphabetic), islower, isupper, isdigit, isxdigit (hexadecimal)
    // iscntrl (control characters e.g '\n', '\t', '\r', '\b'), isgraph (graphical), isspace (' ', '\t', '\n', '\r', '\f', '\v')
    // isblank (' ', '\t'), isprint (printable character), ispunct (punctuation).
    // Cstring functions:
    cout << strlen(message2) << endl;  // returns length excluding null character.
    cout << sizeof(message2) << endl;  // returns length including null character.
    const char* filename = strrchr("C:\\Users\\Hassaan\\Desktop\\Programming\\C++", '\\') + 1;
    cout << filename << endl;  // dynamic char array (char pointer) in pointer doc.
    // strrchr is used to get string after last occurrence of specified character. +1 to point after the specified character.
    // strchr is used to get first occurrence of specified character.
    // both return nullptr if not found.
    char fullmessage[100];
    strcpy_s(fullmessage, message2);  // copies one string to another. (fullmessage = message2)
    strcat_s(fullmessage, " World!");  // concatenates two strings. (fullmessage + " World!")
    cout << fullmessage << endl;

    // 2D Arrays:
    int arr2[3][3];  // 2D array of 3 rows and 3 columns created.
    int packages[][4]{  // initialising a 2D array with values.
       {1,2,3,4},
       {5,6,7,8},
       {9,10,11,12},
       {3,4,5,6}};  
    // for any multi-dimensional array, you have to specify the number of elements in []'s, only the left most is not mandatory.
    int Rows = sizeof(arr2) / sizeof(arr2[0]);  // number of rows
    int Columns = sizeof(arr2[0]) / sizeof(arr2[0][0]);  // number of columns 

    

	return 0;
}