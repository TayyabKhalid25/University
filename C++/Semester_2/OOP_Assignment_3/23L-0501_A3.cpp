#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

// Helper Function for comparison.
char to_Lower(const char& character)
{
	if (character >= 'A' && character <= 'Z')
		return (character - ('A' - 'a'));
	return character;  // else return as is.
}

// Helper Class for string implementation.
class PString {
private:
    char* str;
    int len = 0;

public:
	// Default Constructor
	PString() { str = 0; }

    // Parameterised Constructor
    PString(const char* cstring) {
        while (cstring[len] != '\0')  // Length finder
            len++;
        str = new char[len + 1];
        for (int i = 0; i < len; i++)  // string deep copy
            str[i] = cstring[i];
		str[len] = '\0';
    }

    // Copy Constructor
    PString(PString& rhs) {
        this->len = rhs.len;
        this->str = new char[this->len + 1];
        for (int i = 0; i < this->len; i++)  // string deep copy
            this->str[i] = rhs.str[i];
		this->str[this->len] = '\0';
    }

    // Destructor
    ~PString() {
        if (str)
            delete[] str;
    }

	// Return Length
	int length () const { return len; }

    // Assignment Operators
    PString& operator=(const PString& rhs) {
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

	PString operator=(const char* rhs) {
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
	PString operator+(const PString& rhs) const {
		char* temp = new char[this->len + rhs.len + 1];  // +1 for '\0'
		for (int i = 0; i < this->len; i++)
			temp[i] = this->str[i];
		for (int i = this->len; i < this->len + rhs.len; i++)
			temp[i] = rhs.str[i - this->len];
		temp[this->len + rhs.len] = '\0';
		PString newStr(temp);
		delete[] temp;  // Not a problem since temp was deep copied.
		return newStr;
	}
	PString operator+(const char* rhs) const {
		int rhsLen = 0;
		while (rhs[rhsLen] != '\0')  // Length finder
			rhsLen++;
		char* temp = new char[this->len + rhsLen + 1];  // +1 for '\0'
		for (int i = 0; i < this->len; i++)
			temp[i] = this->str[i];
		for (int i = this->len; i < this->len + rhsLen; i++)
			temp[i] = rhs[i - this->len];
		temp[this->len + rhsLen] = '\0';
		PString newStr(temp);
		delete[] temp;
		return newStr;
	}

	// Comparison Operator
	bool operator==(const PString& rhs) const {
		if (this->len == rhs.len) {
			for (int i = 0; i < this->len && i < rhs.len; i++) {
				if (to_Lower(this->str[i]) != to_Lower(rhs.str[i]))
					return 0;
			}
			// cstring1 == cstring2, hence return 1.
			return 1;
		}
		return 0;  // Length aint same.
	}

	// Char Accessor
	char operator[](int i) const {
		return str[i];
	}

    // Output Stream Operator
    friend ostream& operator<<(ostream& out, const PString& rhs) {
        out << rhs.str;
        return out;
    }

	// Input Stream Operator
	friend istream& operator>>(istream& in, PString& rhs) {
		char buffer[500];  // temp buffer which is deleted at end of function.
		in >> buffer;
		rhs = buffer;  // uses overloaded operator to assign cstring to class.
		return in;
	}
};

class EvalReport {
private:
	// Static Members:
	static int quizTotal, assignmentTotal, studentTotal, totalComps, lastResult;
	static int* totalMarks;  // Array containing total marks of quizzes and assignments respectively.
	static int* maximumMarks;  // Array containing max marks of quizzes and assignments respectively.
	static int* minimumMarks;  // Array containing min marks of quizzes and assignments respectively.
	static float* averageMarks;  // Array containing average marks of quizzes and assignments respectively.
	
	// Members unique to each object(student info):
	PString rollNo, firstName, lastName;
	int* obtainedMarks;  // Array containing obtained marks of quizzes and assignments respectively.
	int total;  // Variable containing total obtained marks.

	// Helper Function for Searching
	static bool searchWord(const PString& word, const char* cstr, int cstrlen) {
		for (int j = 0; j < word.length(); j++)
		{
			char* substr = new char[cstrlen + 1] {'\0'};  // +1 for null ptr.
			for (int k = 0; k < cstrlen; k++)
				substr[k] = word[j + k];  // Form substring from rollno
			if (PString(substr) == PString(cstr)) {
				delete[] substr;
				return true;
			}
			delete[] substr;
		}
		return false;
	}

public:
	// Default Constructor
	EvalReport() { obtainedMarks = 0; total = 0; }

	// Parameterised Constructor
	EvalReport(ifstream& fin) {
		fin >> rollNo >> firstName >> lastName;
		obtainedMarks = new int[totalComps];
		total = 0;
		for (int i = 0; i < totalComps; i++) {
			fin >> obtainedMarks[i];
			total += obtainedMarks[i];  // Forms total obtained marks.
		}
	}

	// Copy Constructor
	EvalReport(const EvalReport& rhs) {
		this->rollNo = rhs.rollNo;
		this->firstName = rhs.firstName;
		this->lastName = rhs.lastName;
		this->total = rhs.total;
		this->obtainedMarks = new int[totalComps];
		for (int i = 0; i < totalComps; i++)
			this->obtainedMarks[i] = rhs.obtainedMarks[i];
	}

	// Destructor
	~EvalReport() {
		if (obtainedMarks)
			delete[] obtainedMarks;  // Delete the only dynamic array in this object.
	}

	// Assignment Operator
	EvalReport& operator=(const EvalReport& rhs) {
		this->rollNo = rhs.rollNo;
		this->firstName = rhs.firstName;
		this->lastName = rhs.lastName;
		this->total = rhs.total;
		for (int i = 0; i < totalComps; i++)
			this->obtainedMarks[i] = rhs.obtainedMarks[i];
		return *this;  // This return is used for cascading assignment, not necessary in this scope.
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

	// Static Function for setting total marks of each component:
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
		averageMarks = new float[totalComps] {0};  // Initialised with 0, will add marks of all students then at end divide by totalstudents.
		
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
			averageMarks[i] /= (float)studentTotal;  // divide by total to obtain average.
	}

	// Function 3 & 5 & 7 (Global):
	static void PrintAll(EvalReport** students, bool printStats = true, bool result = false) {
		cout << setfill('-') << setw(80) << '-' << endl << setfill(' ');
		if (printStats){  // Print max, average, total, etc. if printStats == true:
			cout << setw(7) << " ";
			for (int i = 0; i < totalComps; i++) { // Loops through assessment components.
				char comp[3]{ 0 };
				comp[0] = ((i < quizTotal) ? 'Q' : 'A');
				comp[1] = '0' + ((i < quizTotal) ? i + 1 : i + 1 - quizTotal);
				comp[2] = '\0';
				cout << setw(8) << comp;  // Prints component names.
			}
			cout << endl << left << setw(13) << "Total:";
			for (int i = 0; i < totalComps; i++)
				cout << setw(8) << totalMarks[i];
			cout << endl << left << setw(13) << "Maximum:";
			for (int i = 0; i < totalComps; i++)
				cout << setw(8) << maximumMarks[i];
			cout << endl << left << setw(13) << "Minimum:";
			for (int i = 0; i < totalComps; i++)
				cout << setw(8) << minimumMarks[i];
			cout << endl << left << setw(13) << "Average:";
			for (int i = 0; i < totalComps; i++)
				cout << fixed << setprecision(2) << setw(8) << averageMarks[i];
			cout << endl << setfill('-') << setw(80) << '-' << endl << setfill(' ');

		}
		// Print Student Data:
		cout << left << setw(10) << "Roll No."
			<< setw(20) << "Name";
		for (int i = 0; i < totalComps; i++) { // Loops through assessment components.
			char comp[3]{ 0 };
			comp[0] = ((i < quizTotal) ? 'Q' : 'A');
			comp[1] = '0' + ((i < quizTotal) ? i + 1 : i + 1 - quizTotal);
			comp[2] = '\0';
			cout << setw(5) << comp;  // Prints component names.
		}
		cout << setw(10) << "Total" << endl;

		for (int i = 0; i < ((result) ? lastResult : studentTotal); i++)  // Loops through students.
		{
			cout << left << setw(10) << students[i]->rollNo
				<< setw(20) << students[i]->firstName + " " + students[i]->lastName;
			for (int j = 0; j < totalComps; j++)   // Loops through assessment components.
				cout << setw(5) << students[i]->obtainedMarks[j];  // Prints marks.
			cout << setw(10) << students[i]->total << endl;
		}
	}

	// Function 4 (Global):
	static EvalReport** SearchStudentsByKeyWord(EvalReport** students, const char* cstr) {
		int cstrlen = 0;
		while (cstr[cstrlen] != '\0')  // find length of str.
			cstrlen++;

		lastResult = 0;  // Index of number of results found.
		EvalReport** result = 0;

		for (int i = 0; i < studentTotal; i++)
		{
			bool found = searchWord(students[i]->rollNo, cstr, cstrlen);  // Search in rollNo
			if (!found)  // Search in firstname if not found in rollNo
				found = searchWord(students[i]->firstName, cstr, cstrlen);
			if (!found)  // Search in lastname if not found in firstname
				found = searchWord(students[i]->lastName, cstr, cstrlen);
			
			if (found) {  // Add record of student to new array.
				lastResult++;  // Increment count of array
				EvalReport** temp = result;
				result = new EvalReport * [lastResult];
				for (int j = 0; j < lastResult - 1; j++)
					result[j] = temp[j];  // Copy pointers of prev list
				result[lastResult - 1] = students[i];  // Add pointer to new found record.
				if (temp)
					delete[] temp;
			}
		}

		return result;
	}

	// Function 6 (Global):
	static void SortListByTotal(EvalReport** students) {
		for (int i = 0; i < studentTotal - 1; i++) {
			int maxIndex = i;
			for (int j = i + 1; j < studentTotal; j++) {
				// Select the max total in each loop.
				if (students[j]->total > students[maxIndex]->total)
					maxIndex = j;
			}
			// put student at the correct position:

			// Using Pointers (Preferred):
			EvalReport* temp = students[maxIndex];
			students[maxIndex] = students[i];
			students[i] = temp;

			// Following Swap will Also work by help of Copy Constructor and overloaded '=' Operator:
			//EvalReport temp = *students[i];
			//*students[i] = *students[maxIndex];
			//*students[maxIndex] = temp;
		}
	}

	// Function 8 (Global):
	static void PrintDetailView(EvalReport** students, const char* rollNo) {
		EvalReport** student = SearchStudentsByKeyWord(students, rollNo);
		if (student) { // If found:
			// Student Info
			cout << endl << left << setw(20) << "Roll No:" << (*student)->rollNo << endl 
				<< left << setw(20) << "Name:" << (*student)->firstName + " " + (*student)->lastName;
			// Assignment Marks
			cout << "\n\n" << left << setw(16) << "Assignment#"
				<< left << setw(16) << "Obtained Marks"
				<< left << setw(16) << "Total Marks"
				<< left << setw(16) << "Average"
				<< left << setw(16) << "Minimum"
				<< left << setw(16) << "Maximum";
			for (int i = 0; i < assignmentTotal; i++)
				cout << endl << setw(16) << i + 1
					<< setw(16) << (*student)->obtainedMarks[quizTotal + i]
					<< setw(16) << totalMarks[quizTotal + i]
					<< fixed << setprecision(2) << setw(16) << averageMarks[quizTotal + i]
					<< setw(16) << minimumMarks[quizTotal + i]
					<< setw(16) << maximumMarks[quizTotal + i];
			// Quiz Marks
			cout << "\n\n" << left << setw(16) << "Quiz#"
				<< left << setw(16) << "Obtained Marks"
				<< left << setw(16) << "Total Marks"
				<< left << setw(16) << "Average"
				<< left << setw(16) << "Minimum"
				<< left << setw(16) << "Maximum";
			for (int i = 0; i < quizTotal; i++)
				cout << endl << setw(16) << i + 1
				<< setw(16) << (*student)->obtainedMarks[i]
				<< setw(16) << totalMarks[i]
				<< fixed << setprecision(2) << setw(16) << averageMarks[i]
				<< setw(16) << minimumMarks[i]
				<< setw(16) << maximumMarks[i];
			// Total
			cout << "\n\nTotal:\t\t" << (*student)->total << endl;
		}
		else
			cout << "\nStudent not found :(\n";
	}

	// Static Function for deleting dynamically allocated static data, as well as list of students.
	static void deleteData(EvalReport** students, EvalReport** result) {
		delete[] result;
		for (int i = 0; i < studentTotal; i++)
			delete students[i];  // Deletes each individual object holding info about student.
		delete[] students;  // Deletes the pointer array which pointer to each student.
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
int EvalReport::lastResult = 0;
int* EvalReport::totalMarks = 0;
int* EvalReport::maximumMarks = 0;
int* EvalReport::minimumMarks = 0;
float* EvalReport::averageMarks = 0;




int main()
{
	EvalReport** students = EvalReport::ReadDataFromFile();
	EvalReport::UpdateStatistics(students);
	EvalReport::PrintAll(students);
	cout << "\nSearching for \"43\" in name and roll number....\n";
	EvalReport** result = EvalReport::SearchStudentsByKeyWord(students, "43");
	EvalReport::PrintAll(result, false, true);
	cout << "\nSorting Student List by Total Obtained Marks and Printing....\n";
	EvalReport::SortListByTotal(students);
	EvalReport::PrintAll(students, false);
	cout << "\nPrinting Detailed View of 15L-1234....\n";
	EvalReport::PrintDetailView(students, "15L-1234");
	cout << "\nPrinting Detailed View of 15L-4023....\n";
	EvalReport::PrintDetailView(students, "15L-4023");


	EvalReport::deleteData(students, result);
	return 0;
}