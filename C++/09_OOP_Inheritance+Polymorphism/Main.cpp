#include <iostream>
using namespace std;

// class BankAccount;  // Forward Declaration does not seem to work in allowing usage of that class elsewhere, whole class defintion needs to be at top.

// Base Class / Example Class
class BankAccount {
private:
    int accountNumber;
    string accountHolderName;
    float* balance;

public:
    // Parameterized Constructor:
    BankAccount(int accountNumber = -1, string accountHolderName = "temp", float balance = 0.0f) {
        this->accountNumber = accountNumber;
        this->accountHolderName = accountHolderName;
        this->balance = new float(balance);
    }

    // Copy Constructor:
    BankAccount(const BankAccount& a) {
        accountNumber = a.accountNumber;
        accountHolderName = a.accountHolderName;
        balance = new float(*a.balance);
    }

    // Assignment Operator:
    BankAccount& operator=(const BankAccount& rhs) {
        if (this != &rhs) {
            accountNumber = rhs.accountNumber;
            accountHolderName = rhs.accountHolderName;
            delete balance;
            balance = new float(*rhs.balance);
        }
        return *this;
    }

    // Destructor:
    virtual ~BankAccount() {
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
        return this; // As the pointer is returned, you can use -> operator to call further functions. (example in main)
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

    // Virtual function to demonstrate polymorphism
    virtual void accountType() const {
        cout << "This is a Bank Account." << endl;
    }

    // Following are pure virtual functions that have no definition in base class, but are defined in derived classes.
    // Having atleast 1 pure virtual function makes the class an abstract class.
    // Having only pure virtual functions makes it an interface class.
    // Both types make that class unavailable to use outside of inheritance, i.e abstract class obj cannot be created.
    
    /* virtual SavingAccount* setInterestRate(float rate) = 0;
       virtual float getInterestRate() const = 0;
    */
};
// Relations between classes consist mainly of Inheritance(is-a), Composition(has-a[strong]), Aggregation(has-a[weak]), Association(general), Dependency(uses-a).

//Composition:
class composition {
	BankAccount obj;
	BankAccount* obj2;
	// Both of the above should be initialised in all constructors to be valid composition.
public:
	composition(BankAccount& a) : obj(a) {	// deep copy of a is made, obj initialised.
		obj2 = new BankAccount;  // Initialised with default values.
	}
	~composition() {
		delete obj2;  // Default constructor will only delete objects on stack, for heap(dynamic) we need to explicitly delete in destructor.
	}
};

// Aggregation:
class aggregation {
	BankAccount* obj;
	// Does not need to be initialised in constructors, and will only contain address of an external object that can be modified here.
public:
	aggregation(BankAccount* a) : obj(a) {}  // Aggregation is basically a shallow copy.
	void getObj(BankAccount* a) { obj = a; }  // A getter type function can also be used to change obj addresses.
	~aggregation() {}  // Will not delete the pointer, because life is not controlled here of that obj.

};

// Dependancy: 
class dependant {
	string name;
public:
	void function(BankAccount& obj) {  // The function is dependant on the class BankAccount.
		name = obj.getAccountHolderName();
	}
	friend ostream& operator<<(ostream& out, dependant& a) {  // Function dependant on ostream class.
		out << a.name;
		return out;
	}
};

// Inheritance:
// Three types of inheritance, public, protected, private. Through this we can control how relaxed or constrained is the access of base class members
// from derived class. Private members will never be accessible from derived class, while protected will be available in all inheritances except private.
// Final keyword makes it so that the class will not be inherited further.

class SavingAccount final : public BankAccount {
private:
    float interestRate;

public:
    // Parameterized Constructor, constructor of base class is called using member initialiser list, if omitted default constructor called of base class.
    SavingAccount(int accountNumber = -1, string accountHolderName = "temp", float balance = 0.0f, float interestRate = 0.0f)
        : BankAccount(accountNumber, accountHolderName, balance), interestRate(interestRate) {}

    // Copy Constructor:
    SavingAccount(const SavingAccount& sa) : BankAccount(sa) {
        interestRate = sa.interestRate;
    }

    // Assignment Operator(NOT OVERLOADED):
    SavingAccount& operator=(const SavingAccount& rhs) {
        if (this != &rhs) {
            BankAccount::operator=(rhs);  // If base class function is also to be used, write class::function.
            interestRate = rhs.interestRate;
        }
        return *this;
    }

    // Overloaded Destructor, can only be done if base class's destructor is virtual, which is necessary for deletion of derived class obj as well. 
    // override keyword is not required but helps compiler eliminate compile time errors related to this.
    ~SavingAccount() override {
        cout << "Destructor of SavingAccount called....\n";
    }

    // Setters:
    SavingAccount* setInterestRate(float rate) {
        interestRate = rate;
        return this;
    }

    // Getters:
    float getInterestRate() const {
        return interestRate;
    }

    // Override virtual function from base class.
    void accountType() const override {
        cout << "This is a Saving Account with interest rate: " << interestRate << "%" << endl;
    }
};

int main() {
    BankAccount* sa = new SavingAccount(12345, "John Doe", 1000.0f, 2.5f);

    cout << "Account Number: " << sa->getAccountNumber() << endl;
    cout << "Account Holder Name: " << sa->getAccountHolderName() << endl;
    cout << "Balance: " << sa->getBalance() << endl;

    sa->accountType(); // This will call the overridden method in SavingAccount

    delete sa;
    return 0;
}

// Multiple Inheritance and Diamond Problem:
// Suppose student and teacher inherit person, and TA inherits both student and teacher, two instance of person's data members will be created normally.
// To avoid it, virtual inheritance is required.
// However, if interface/abstract class with no data members, then no problem should arise.

class person {};
class student : virtual public person {};
class teacher : virtual public person {};
class TA : public student, public teacher {};

