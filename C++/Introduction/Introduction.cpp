#include <iostream>
#include <iomanip>
#include <ios>
#include <cmath>
using namespace std; 
int main()
{

    int initial = 20; // this is the normal way.
    int initialize{ 20 }; // this is a way to initialise without equal sign. can be done with normal parentheses, but they may convert decimal to int silently(implicitly).
    // int is by default signed int, with 4 bytes of storage. short has 2 bytes, and long has 4 or 8 bytes, while long long has 8 bytes.
    // short and char datatypes do not support arithmetic operations.
    int num1{ 2 };
    signed short num2{ 20 }; // this is default.
    unsigned short num3{ 20 }; // cannot store negative numbers.
    long num4{ 2000 };
    long long num5{ 1000 }; // largest possible storage of integer.
    // for floating point representation, we have float, double and long double. float has size of 4 bytes, double 8 bytes, long double 12 bytes.
    // precision of float is 7, double is 15, and long double is more than that. precision can be controlled by std::setprecision(value).
    double num6{ 192400023 };
    double num7{ 1.9240023e8 }; // same number as above, but in scientific notation. e for exponent of 10.
    double num8{ 0.00003948 };
    double num9{ 3.948e-5 }; // same number as above.
    // you can divide +ve and -ve number with 0 to obtain +ve infinity and -ve infinity respectively. you can also divide 0 with 0 to get nan (not a number).
    // when declaring and initialising decimals, use appropriate suffixes if not double, since default is double.
    float num10{ 1.12345678901234567890f };
    double num11{ 1.12345678901234567890 };
    long double num12{ 1.12345678901234567890l };
    // bool is the boolean datatype. can store either true or false. when printed however, it will print 1 if true, and 0 if false.
    // unless we use std::boolalpha, which forces it output to true/false.
    // bool uses 1 byte, which is wasteful, but yeah there are complex ways for more memory management.
    char character{ 'a' }; // we must use single quotation marks for char values.
    char character1{ 97 }; // we can also use the ascii number for whatever char we want, e.g 97 for a.
    // char uses 1 byte. if we want to print the ascii code for the char variable, we use static_cast<int>(value).
    cout << static_cast<int>(character);
    // implicit casting is when C++ silently converts the datatype, like when you assign float to int.
    // explicit casting includes using parantheses before a variable or using static_cast.
    // static_cast<datatype> is widely used and preferred. 
    // auto is a datatype that will automatically deduce the datatype of the initialiser value and convert into that datatype.
    auto number{ 11 };
    // all arithmetic operators: +,-,*,/(integer division)(cant get fractional numbers unless using double/float),%(modulus).
    // incrementation and decrementation can be done with ++ and -- respectively. cant use ** or //.
    int value{ 5 };
    value = value + 1;
    value++; // has same result of incrementation as above statement. can only increment by 1 using ++.
    // above example is postfix, if used in a cout statement, wont display incremented value till next cout, however if we use in 
    // prefix, we can display incremented value in same output.
    ++value;
    // we can also use compound assignment operators as well in c++ like +=, -=, *=, /=, %=.
    value *= 2;
    // comparison operators consist of <,>,<=,>=,==,!=. == and != have lower precedence than the rest. always use parentheses for 
    // comparison of values/variables.
    bool condition = (2 < 10); // will be false.
    // logical operators consist of &&(and), ||(or), !(not).
    // Output Formatting:
    // std::endl and \n have the same usage: Newline.
    // #include <iomanip> is required for functions like std::setw. setw useful for making table.
    std::cout << "Formatted table : " << std::endl << std::left << std::setfill('-');
    cout << std::setw(10) << "Lastname" << std::setw(10) << "Firstname" << std::setw(5) << "Age" << std::endl;
    cout << std::setw(10) << "Daniel" << std::setw(10) << "Gray" << std::setw(5) << "25" << std::endl;
    std::cout << std::setw(10) << "Stanley" << std::setw(10) << "Woods" << std::setw(5) << "33" << std::endl;
    std::cout << std::setw(10) << "Jordan" << std::setw(10) << "Parker" << std::setw(5) << "45" << std::endl;
    std::cout << std::setw(10) << "Joe" << std::setw(10) << "Ball" << std::setw(5) << "21" << std::endl;
    std::cout << std::setw(10) << "Josh" << std::setw(10) << "Carr" << std::setw(5) << "27" << std::endl;
    std::cout << std::setw(10) << "Izaiah" << std::setw(10) << "Robinson" << std::setw(5) << "29" << std::endl;
    // std::right, std::left and std::internal are used for justifying the contents. internal makes sign left justified and data right justified. 
    // once justified, all next cout statements will have that effect, unless justification is changed.
    // std::setfill() will fill the empty spaces left by setw in table with the char specified.
    // https://en.cppreference.com/w/cpp/io/manip Follow link for all output formatting functions.
    // https://en.cppreference.com/w/cpp/header/cmath Follow link for <cmath> functions. All math functions are here.
    // if, elseif,else statements:
    bool Red{false};
    bool Orange{false};
    if (Red){
        // {} brackets are needed to run multiple lines
    }else if (!Orange){ // usage of ! with any condition will basically be used as a NOT operator.
        cout << "Babies." << endl;
    }else{
    cout << "damn";}
    if (num1 > num2) // u can omit {} if only one statement is to be run.
        cout << "Damn";
    // switch/case statements:
    int tool{ 1 };
    switch (tool)
    {
    case 1: {
        std::cout << "Active tool is Pen" << std::endl;
    }break;  // if break is not used, all further lines will be executed, regardless of whether case condition is met or not.
    case 2: {
        std::cout << "Active tool is Marker" << std::endl;
    }break;
    default: {
        std::cout << "Wrong option selected";
    }break;
    }
    // Ternary Operators:
    int Max = (num1 > num2) ? num1 : num2;  // int Max{(num1 > num2) ? num1 : num2}; 
    // this is the same as the code below:
    if (num1 > num2) {
        int max = num1;
    }else {
        int max = num2;
    }
    // For Loop:
    // for (iterator{startingpoint}, test, increment). The iterator can be declared outside, so that it can be used outside the loop as well.
    for (int i{ 0 }; (i < 10); i++) {
        cout << "C++ has a lot of options.\n";
    }
    // While Loop:
    int i{ 0 };
    while (i < 10)
    {
        cout << "C++ has a lot of options.\n";
        i++;
    }
    // Do While Loop: (Alternative of Repeat untill, runs the code first, checks condition later.
    do
    {
        cout << "C++ has a lot of options.\n";
        i++;
    } while (i < 10);
    // Arrays:
    int scores[10];  // square brackets used for arrays. arrays start from 0. [10] means 0 - 9, meaning 10 total elements. diff from python.
    int salary[]{ 1,2,5,11,13,15 }; // u can initialise array with elements, and can also omit size. 
    int families[5]{ 2,2,1 }; // no need to put values in all elements.
    // Range based For Loop using array.
    int sum{ 0 };
    for (int element : salary) {
        sum += element;
    }  // sum will be calculated of all the elements in the array, Range Based For Loop.
    // std::size(array) will output total elements of array.(C++17)
    // Before C++17, sizeof(array)/sizeof(array[0]) would be used.
    char message[5]{ 'H','e','l','l','o' };
    char message2[6]{ 'H','e','l','l','o' };  // if done by omitting size, no null terminator will be at end of array. 
    cout << message << endl;  // will print hello, but with garbage characters since no null value was found at the end of array.
    cout << message2 << endl;  // will print hello normally since a null value was at end of array. Null value is \0.
    char message3[]{ "Hello World!" };
    cout << message3 << endl;  //initialising with a string and omitting size will give it a null terminator at the end of array.
    // can't print arrays other than char datatype using the same methods.
    // Pointers
    int* var1{&num1}, * var2{nullptr}, * var3, var4; // * before variable name initialises it as pointer. int pointer can only point to int variables.
    // All pointers have same size. var4 is regular variable. &num1 gives the address of num1.
    // All pointers are initialised with nullptr by default. Dont cout pointers with nullptr.
    int* dpointer = new int; //Dynamically made a pointer to a memory slot permanently, until delete <variablename> is used. Scope is global, can be accessed from anywhere.
    *dpointer = 77;  // This is how you access data from a pointer variable.
    delete dpointer;  // Never use delete twice on a pointer.
    dpointer = nullptr; // just to play it safe, ensure no random memory is accessed.

    // COMPLETE POINTERS SECTION ABOVE.
    // MOVE POINTER SECTION TO A SEPERATE FILE
    // MAKE SEPERATE SORT AND SEARCH FILE
    // MAKE SEPERATE FUNCTIONS FILE
    // MAKE SEPERATE FILE HANDLING FILE
    // MAKE SEPERATE OOP FILE






    return 0;
}
