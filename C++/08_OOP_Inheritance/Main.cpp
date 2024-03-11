#include <iostream>
using namespace std;
// Continue from 22:59:20

// Sample Class below for Syntax.
class BankAccount 
{  
private:
	int accountNumber;
	string accountHolderName;
	float* balance = new float;

public:
	// Parameterised Constructor:
	BankAccount(int accountNumber = -1, string accountHolderName = "temp", float balance = 0.0f) {
		this->accountNumber = accountNumber;
		this->accountHolderName = accountHolderName;
		*this->balance = balance;
	}
	// Copy Constructor:
	BankAccount(const BankAccount& a){  
		accountNumber = a.accountNumber;
		accountHolderName = a.accountHolderName;
		*balance = *a.balance;  
	}
	// Destructor:
	~BankAccount() {
		cout << "Destructor of BankAccount called....\n";
		delete balance;
	}
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
	// Getters:
	int getAccountNumber() const { 
		return accountNumber;
	}
	string getAccountHolderName() const {
		return accountHolderName;
	}
	float getBalance() const {
		return *balance;
	}

};  




int main()
{
	

	return 0;
}