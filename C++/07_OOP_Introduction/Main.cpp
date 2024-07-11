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
};  // Semi-colon necessary.

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
	/*BankAccount() {
		accountNumber = -1;
		accountHolderName = "temp";
		*balance = 0.0f;
	}*/

	// if we dont have a parameterised constructor, then default is not needed, but if we have, then
	// either we make a default constructor, or include default arguments to eliminate the need for it.
	
	// Parameterised Constructor, called when parameters given:
	BankAccount(int accountNumber = -1, string accountHolderName = "temp", float balance = 0.0f) {
		// "this" is a hidden pointer for all classes, which points to address of current object. 
		// It is useful when parameter name and member name are the same, to differentiate between them.
		this->accountNumber = accountNumber;
		this->accountHolderName = accountHolderName;
		*this->balance = balance;
	}
	
	// Copy Constructor, called when passing an instance/object of the same class, or assigning the 
	// object using '=' during initialization, keep in mind assignment outside of declaration
	// requires an overloaded '=' operator. 
	
	// If we dont define a copy constructor, the compiler provides a default copy constructor which 
	// performs a member-wise shallow copy, that can be unwanted in the case of memory on heap.

	// Copy Constructor:
	BankAccount(const BankAccount& a){  // const to prevent modification and all function calls which are not defined with const,
	// passing by reference(&) is required to prevent recursive duplication from starting. 
		accountNumber = a.accountNumber;
		accountHolderName = a.accountHolderName;
		*balance = *a.balance;  // Deep copy needed for Dynamic Variables.
		// a.accountNumber = 2;   This is an illegal statement because we have used const.
		// a.getAccountNumber();  This is an illegal statement only if the function is not defined
		// with const, e.g int getAccountNumber();.
	}

	// Destructors are called for each instance/object when they go out of scope, in OPPOSITE/REVERSE order of 
	// declaration of objects, e.g end of main. If the object is created dynamically(new myClass),
	// then it is called during delete statement. Destructors are only relevant if we use dynamic memory
	// allocation within classes, to delete said memory from heap. Common problem is when object is passed
	// by value to a function, so a shallow copy is made, and when the copy goes out of scope, the 
	// destructor will be called twice, hence any delete statements within will also be called twice,
	// resulting in error. Solution is to always pass objects by reference to functions.

	// Destructor:
	~BankAccount() {
		cout << "Destructor of BankAccount called....\n";
		delete balance;
	}

	// Setter and Getter set and get values of variables within a class respectively.
	// Setters:
	void setAccountNumber(int a) {
		accountNumber = a;
	}
	// Chained calls using pointers in Setters:
	BankAccount* setAccountHolderName(string accountHolderName) {
		this->accountHolderName = accountHolderName;
		return this;  // As the pointer is returned, you can use -> operator to call further functions.(example in main)
	}
	BankAccount* setBalance(float balance) {
		*this->balance = balance;
		return this;
	}
	// Chained calls using addresses in Setters:
	//BankAccount& setAccountHolderName(string accountHolderName) {
	//	this->accountHolderName = accountHolderName;
	//	return *this;  // As the address is returned, you can use . operator to call further functions.(example in main)
	//}
	//BankAccount& setBalance(float balance) {
	//	*this->balance = balance;
	//	return *this;
	//}

	// Getters:
	int getAccountNumber() const {  // const after function name allows this function to be called even if the object is declared with const keyword.
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
	// Implementation of above classes:
	group1.num1 = 20;  // The global variable created in beginning of struct is available here.
	student student1;  // An object/instance created of the struct student.
	student student2{ 10, "Tayyab", "Somewhere"};  // The object is also initialised with values for the variables/members within.
	student student3 = student2;  // Not tested, but expect a shallow copy to be made.
	student1.ID = 100;  // Method for accessing variables/members of object.
	
	student* studentPtr = new student{ student1 };  // studentPtr points to memory on heap, object initialised with values of student1.
	(*studentPtr).name = "Wahaj";  // Method for accessing variables/members of objects made on heap.
	studentPtr->name = "Wahaj";  // Better implementation of above line.
	
	BankAccount account1;  // Object account1 of class BankAccount created with default constructor.
	BankAccount account2(2004, "Tayyab", 500.5);  // Object account2 created with parameterised constructor.
	BankAccount account3(account2);  // Object account3 created with copy constructor, it has same values as account2 now.
	account1.setAccountHolderName("Wahaj");  // Using setter to set new value of member. Similarly use getter to get value.
	// BankAccount account3 = account2;  // Same as above line.
	// BankAccount account3{ account2 };  // Same as above line.
	
	BankAccount* accountPtr = new BankAccount(account1);  // accountPtr points to memory on heap, object initialised with values of account1.
	cout << (*accountPtr).getBalance() << "\t<-- Balance of accountptr\n\n";  // Method for accessing members/methods of objects made on heap.
	cout << accountPtr->getBalance() << "\t<-- Balance of accountptr\n\n";  // Better implementation of above line.

	// Chained Calls using pointers:
	accountPtr->setAccountHolderName("Faizan")->setBalance(2000.10)->setAccountNumber(1);  // Only possible if method returns "this".
	// Chained Calls using addresses:
	// accountPtr->setAccountHolderName("Faizan").setBalance(2000.10).setAccountNumber(1);  // Only possible if method returns "*this".

	// When using sizeof(object), we can expect to see the sum of memory of all variables in that object.
	// However, if there is string variable, it wont return proper size, as string is a const char*, so it will always have fixed size regardless
	// of string size, which does not denote the size of the string itself.


	return 0;
}