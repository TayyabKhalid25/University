#include <iostream>
using namespace std;

int main()
{
    // Pointers:
    int num1 = 20;
    int* var1{ &num1 }, * var2{ nullptr }, * var3, var4; // * before variable name initialises it as pointer. int pointer can only point to int variables.
    // All pointers have same size. var4 is regular variable. &num1 gives the address of num1.
    // All pointers are initialised with nullptr by default. Dont cout pointers with nullptr.
    int* dpointer = new int; //Dynamically made a pointer to a memory slot permanently, until delete <variablename> is used. Scope is global, can be accessed from anywhere.
    *dpointer = 77;  // This is how you access data from a pointer variable.
    delete dpointer;  // Never use delete twice on a pointer.
    dpointer = nullptr; // just to play it safe, ensure no random memory is accessed.

    // COMPLETE POINTERS SECTION ABOVE (10:46:06).
	return 0;
}