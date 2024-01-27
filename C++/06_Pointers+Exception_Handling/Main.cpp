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


    
    // COMPLETE POINTERS SECTION ABOVE (10:46:06).
	return 0;
}

