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
    dpointer = nullptr; // just to play it safe, ensure no random memory is accessed. 0 or NULL or {} can also be used.
    // Dangling pointers if uninitialised, deleted, or multiple pointers pointing to same address.
    // Good practice to always intialise properly and after deleting, assign nullptr.
    // Always check if pointer is not pointing to nullptr to ensure no crash happens.

    
    // COMPLETE POINTERS SECTION ABOVE (10:46:06).
	return 0;
}

