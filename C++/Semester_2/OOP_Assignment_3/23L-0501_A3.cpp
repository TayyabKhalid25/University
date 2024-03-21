#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

// Helper Class for string implementation.
class String {
private:
    char* str;
    int len = 0;

public:
	// Default Constructor
	String() { str = 0; }

    // Parameterised Constructor
    String(const char* cstring) {
        while (cstring[len] != '\0')  // Length finder
            len++;
        str = new char[len + 1];
        for (int i = 0; i < len; i++)  // string deep copy
            str[i] = cstring[i];
		str[len] = '\0';
    }

    // Copy Constructor
    String(String& rhs) {
        this->len = rhs.len;
        this->str = new char[this->len + 1];
        for (int i = 0; i < this->len; i++)  // string deep copy
            this->str[i] = rhs.str[i];
		this->str[this->len] = '\0';
    }

    // Destructor
    ~String() {
        if (str)
            delete[] str;
    }

	// Return Length
	int length() { return len; }

    // Assignment Operators
    String& operator=(const String& rhs) {
        if (this != &rhs) {
			if (str)
				delete[] str;
            this->len = rhs.len;
            this->str = new char[this->len + 1];
			for (int i = 0; i < this->len; i++)  // string deep copy
				this->str[i] = rhs.str[i];
			this->str[this->len] = '\0';
		}
        return *this;
    }

	String operator=(const char* rhs) {
		if (str)
			delete[] str;
		len = 0;
		while (rhs[len] != '\0')  // Length finder
			len++;
		str = new char[len + 1];
		for (int i = 0; i < len; i++)  // string deep copy
			str[i] = rhs[i];
		str[len] = '\0';
		return *this;
	}

	// Concatenation Operators
	String operator+(const String& rhs) {
		char* temp = new char[this->len + rhs.len + 1];  // +1 for '\0'
		for (int i = 0; i < this->len; i++)
			temp[i] = this->str[i];
		for (int i = this->len; i < this->len + rhs.len; i++)
			temp[i] = rhs.str[i];
		temp[this->len + rhs.len] = '\0';
		String newStr(temp);
		delete[] temp;
		return newStr;
	}
	String& operator+(const char* rhs) {
		int rhsLen = 0;
		while (rhs[rhsLen] != '\0')  // Length finder
			rhsLen++;
		char* temp = new char[this->len + rhsLen + 1];  // +1 for '\0'
		for (int i = 0; i < this->len; i++)
			temp[i] = this->str[i];
		for (int i = this->len; i < this->len + rhsLen; i++)
			temp[i] = rhs[i];
		temp[this->len + rhsLen] = '\0';
		String newStr(temp);
		delete[] temp;
		return newStr;
	}

    // Output Stream Operator
    friend ostream& operator<<(ostream& out, const String& rhs) {
        out << rhs.str;
        return out;
    }

	// Input Stream Operator
	friend istream& operator>>(istream& in, String& rhs) {
		char buffer[500];  // temp buffer which is deleted at end of function.
		in >> buffer;
		rhs = buffer;  // uses overloaded operator to assign cstring to class.
		return in;
	}
};

class EvalReport {
private:
	// Static Members:
	static int quizTotal, assignmentTotal, studentTotal, totalComps;
	static int* totalMarks;  // Array containing total marks of quizzes and assignments respectively.
	static int* maximumMarks;  // Array containing max marks of quizzes and assignments respectively.
	static int* minimumMarks;  // Array containing min marks of quizzes and assignments respectively.
	static int* averageMarks;  // Array containing average marks of quizzes and assignments respectively.
	// Members unique to each object(student info):
	string rollNo, firstName, lastName;
	int* obtainedMarks;  // Array containing obtained marks of quizzes and assignments respectively.



public:
	// Default Constructor
	EvalReport() { obtainedMarks = 0; }

	// Parameterised Constructor
	EvalReport(ifstream& fin) {
		fin >> rollNo >> firstName >> lastName;
		obtainedMarks = new int[totalComps];
		for (int i = 0; i < totalComps; i++)
			fin >> obtainedMarks[i];
	}

	// Destructor
	~EvalReport() {

	}

	// Function 1 (Global):
	static EvalReport** ReadDataFromFile() {  // static because this will be called before creation of objects, and will make the initial array of students.
		ifstream fin("gradesheet.txt");
		setTotals(fin);  // Reads static data(total marks, etc.)
		
		// Make double pointer containing all students.
		EvalReport** students = new EvalReport * [studentTotal];

		// Read Data of students:
		for (int i = 0; i < studentTotal; i++)
			students[i] = new EvalReport(fin);
		fin.close();

		return students;
	}

	// Static Function for setting total marks:
	static void setTotals(ifstream& fin) {  // Static Function which will initialise static members.
		fin >> studentTotal >> quizTotal >> assignmentTotal;
		totalComps = quizTotal + assignmentTotal;
		totalMarks = new int[totalComps];
		for (int i = 0; i < quizTotal; i++)
			fin >> totalMarks[i];
		for (int i = 0; i < assignmentTotal; i++)
			fin >> totalMarks[quizTotal + i];  // By adding quizTotal, we start at index of assignments.
	}

	// Function 2 (Global):
	static void UpdateStatistics(EvalReport** students) {
		maximumMarks = new int[totalComps] {0};  // All are initialised with 0, so that max is updated by first comparison.
		minimumMarks = new int[totalComps] {100};  // Initialised with 100, an extreme value, so that minimum is updated by first comparison.
		averageMarks = new int[totalComps] {0};  // Initialised with 0, will add marks of all students then at end divide by totalstudents.
		
		for (int i = 0; i < studentTotal; i++) {  // loops through students
			for (int j = 0; j < totalComps; j++) {  // loops through all assessment components
				if (students[i]->obtainedMarks[j] > maximumMarks[j])  // max compare
					maximumMarks[j] = students[i]->obtainedMarks[j];
				if (students[i]->obtainedMarks[j] < minimumMarks[j])  // min compare
					minimumMarks[j] = students[i]->obtainedMarks[j];
				averageMarks[j] += students[i]->obtainedMarks[j];  // Adds to average(temporarily total marks of students).
			}
		}

		for (int i = 0; i < totalComps; i++)  // loops through all assessment components
			averageMarks[i] /= studentTotal;  // divide by total to obtain average.
	}

	// Function 3 (Global):
	static void PrintAll(EvalReport** students) {
		cout << setfill('-') << setw(80) << '-' << endl << setfill(' ');
		cout << setw(10) << " ";
		for (int i = 0; i < totalComps; i++) { // Loops through assessment components.
			char comp[3];
			comp[0] = ((i < quizTotal) ? 'Q' : 'A');
			comp[1] = '0' + ((i < quizTotal) ? i + 1 : i + 1 - quizTotal);
			comp[2] = '\0';
			cout << setw(5) << comp;  // Prints component names.
		}
		cout << endl << left << setw(13) << "Total:";
		for (int i = 0; i < totalComps; i++)
			cout << setw(5) << totalMarks[i];
		cout << endl << left << setw(13) << "Maximum:";
		for (int i = 0; i < totalComps; i++)
			cout << setw(5) << maximumMarks[i];
		cout << endl << left << setw(13) << "Minimum:";
		for (int i = 0; i < totalComps; i++)
			cout << setw(5) << minimumMarks[i];
		cout << endl << left << setw(13) << "Average:";
		for (int i = 0; i < totalComps; i++)
			cout << setw(5) << averageMarks[i];
		cout << endl << setfill('-') << setw(80) << '-' << endl << setfill(' ');

		cout << left << setw(10) << "Roll No."
			<< setw(20) << "Name";
		for (int i = 0; i < totalComps; i++) { // Loops through assessment components.
			char comp[3];
			comp[0] = ((i < quizTotal) ? 'Q' : 'A');
			comp[1] = '0' + ((i < quizTotal) ? i + 1 : i + 1 - quizTotal);
			comp[2] = '\0';
			cout << setw(5) << comp;  // Prints component names.
		}
		cout << setw(10) << "Total" << endl;

		for (int i = 0; i < studentTotal; i++)  // Loops through students.
		{
			cout << left << setw(10) << students[i]->rollNo
				<< setw(20) << students[i]->firstName + " " + students[i]->lastName;
			int total = 0;
			for (int j = 0; j < totalComps; j++) {  // Loops through assessment components.
				cout << setw(5) << students[i]->obtainedMarks[j];  // Prints marks.
				total += students[i]->obtainedMarks[j];
			}
			cout << setw(10) << total << endl;
		}
	}

	// Static Function for deleting dynamically allocated static data.
	static void deleteStaticData() {
		if (totalMarks)
			delete[] totalMarks;
		if (maximumMarks)
			delete[] maximumMarks;
		if (minimumMarks)
			delete[] minimumMarks;
		if (averageMarks)
			delete[] averageMarks;
	}
};
// Initialise Static members(necessary)
int EvalReport::totalComps = 0;
int EvalReport::quizTotal = 0;
int EvalReport::assignmentTotal = 0;
int EvalReport::studentTotal = 0;
int* EvalReport::totalMarks = 0;
int* EvalReport::maximumMarks = 0;
int* EvalReport::minimumMarks = 0;
int* EvalReport::averageMarks = 0;




int main()
{
	EvalReport** students = EvalReport::ReadDataFromFile();
	EvalReport::UpdateStatistics(students);
	EvalReport::PrintAll(students);

	return 0;
}

