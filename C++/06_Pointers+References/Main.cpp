#include <iostream>
using namespace std;

int main()
{
    // Pointers:
    int num1 = 20;
    int* var1{ &num1 }, * var2{ NULL }, * var3{}, var4; // * before variable name initialises it as pointer. int pointer can only
    // point to int variables.
    // All pointers have same size. var4 is regular variable. &num1 gives the address of num1.
    // All pointers are initialised with nullptr by default. Dont cout pointers with nullptr.
    int* dpointer = new int; //Dynamically made a pointer to a memory slot permanently, until delete <variablename> is used.
    // Scope is global, can be accessed from anywhere.
    *dpointer = 77;  // This is how you access data from a pointer variable.
    delete dpointer;  // Never use delete twice on a pointer, it will crash.
    // No need to worry about deleting a pointer which points to nullptr, wont crash.
    dpointer = nullptr; // just to play it safe, ensure no random memory is accessed. 0 or NULL or {} can also be used.
    // Dangling pointers if uninitialised, deleted, or multiple pointers pointing to same address.
    // Good practice to always intialise properly and after deleting, assign nullptr.
    // We can check if pointer is not pointing to nullptr to ensure no crash happens or use exception handling.
    if (!(var1 == nullptr))
        cout << "Address is: " << var1 << endl;
    else
        cout << "Doesnt point to anything.\n";
    if (var2)
        cout << "Address is: " << var2 << endl;
    else
        cout << "Doesnt point to anything.\n";
    // Exception Handling:
    try
    {
        int* pointer1 = new int[10000000000000];  // We cant allocate large amount of memory for arrays.
    }
    catch (const std::exception& ex)
    {
        cout << "Error Caught: " << ex.what() << endl;
    }
    // We can also use std::nothrow as alternative to try/catch.
    int* pointer1 = new(nothrow) int[10000000000];
    // Dynamic Arrays:
    // These are different from simple arrays in working as well, cant use std::size or range based for loops.
    double* arr = new double[10];  
    int* points{ new int[5] {} };  // Initialises all elements with 0.
    int* arr1 = new int[6] {0, 1, 2, 3, 4, 5};  // Cant initialise without size, needs a value.
    for (int i = 0; i < 6; i++)
        cout << "Value is: " << arr1[i] << "\nCan also be accessed like this: " << *(arr1 + i) << endl;
    delete[] arr;  // You cant delete multiple memories with one delete.
    delete[] points;
    delete[] arr1;
    
    
    // COMPLETE POINTERS SECTION ABOVE (12:12:40).
	return 0;
}

