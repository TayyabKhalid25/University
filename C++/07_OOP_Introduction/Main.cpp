#include <iostream>
using namespace std;

// There are 3 Access Modifiers, private, public, protected.
// Private: Members are only accessible within class, or by public getter setter functions.
// Public: Members can be accessed by instances/objects of class directly using dot notation.
// Protected: Members can be accessed by all derived and friend classes.(Middle ground b/w public & private)

// Structs and Classes are the same, except for the following:
// - Members of a struct are public by default, while Members of a class are private by default.
// - Inheritance and other complex behaviour works properly in classes only,
//   in structs they may have unexpected behaviour.
 
// Structs and Classes are composite user-defined data types that allow you to group together 
// different data elements of different data types under a single name, along with functions(methods). 

// Sample Struct below for Syntax.
struct student  // The user-defined data type student is now available.
{
	int ID;
	string name;
	string address;
};
struct 
{
	int num1;
	double num2;
} group1, group2;  // group1 & group2 defined with above members. This is valid c++ code, but not recommended.



// Sample Class below for Syntax.
class BankAccount 
{  

// All variables should be private in a class, as a good programming practice.

private:
	// Members cant be reference variables, since needs initialization with declaration hence useless.
	int accountNumber;
	string accountHolderName;
	float* balance = new float;

// In public, all members are accessible through objects via dot notation.
// All functions(methods) should be public in a class.
public:

	// Constructors are called when an instance/object of class is created, it has no return type.
	// Three types of Constructors, default, parameterised, copy.
	
	// Default Constructor, called when no parameters given: 
	BankAccount() {
		accountNumber = -1;
		accountHolderName = "temp";
		*balance = 0.0f;
	}

	// if we dont have a parameterised constructor, then default is not needed, but if we have, then
	// either we make a default constructor, or include default arguments to eliminate the need for it.
	
	// Parameterised Constructor, called when parameters given:
	BankAccount(int a = 0, string b = "", float c = 0.0f) { 
		accountNumber = a;
		accountHolderName = b;
		*balance = c;
	}
	
	// Copy Constructor, called when passing an instance/object of the same class, or assigning the 
	// object using '=' during initialization, keep in mind assignment outside of declaration
	// requires an overloaded '=' operator. 
	
	// If we dont define a copy constructor, the compiler provides a default copy constructor which 
	// performs a member-wise shallow copy, that can be unwanted in the case of memory on heap.

	// Copy Constructor:
	BankAccount(const BankAccount& a){  // const to prevent modification and all function calls,
	// passing by reference(&) is required to prevent recursive duplication from starting. 
		accountNumber = a.accountNumber;
		accountHolderName = a.accountHolderName;
		*balance = *a.balance;  // Deep copy needed for Dynamic Variables.
		// a.accountNumber = 2;   This is an illegal statement because we have used const.
		// a.getAccountNumber();  This is an illegal statement only if the function is not defined
		// with const, e.g int getAccountNumber();.
	}

	// Destructors are called for each instance/object when they go out of scope, in opposite order of 
	// declaration of objects, e.g end of main. 
	// If the object is created dynamically(new myClass), then it is called during delete statement.
	// Destructors are only relevant if we use dynamic memory allocation within classes, to delete 
	// said memory from heap.

	// Destructor:
	~BankAccount() {
		cout << "Destructor of BankAccount called....\n";
		delete balance;
	}

	void setAccountNumber(int a) {
		accountNumber = a;
	}
	void setAccountHolderName(string a) {
		accountHolderName = a;
	}
	void setBalance(float a) {
		*balance = a;
	}
	int getAccountNumber() const {
		return accountNumber;
	}
	string getAccountHolderName() const {
		return accountHolderName;
	}
	float getBalance() const {
		return *balance;
	}

};  // semicolon necessary for class definition.




int main()
{



	// Resume from 20:15:40
	return 0;
}