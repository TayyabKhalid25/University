#include <iostream>
#include <fstream>  // Library required for all file related commands.
#include <string>  // Needed for getline(in, variable)
using namespace std;

int main() 
{
	fstream input;  // fstream object created without opening file.
	// File modes are:
	// ios::in(Input stream/Read)
	// ios::out(Output stream/Write, deletes existing file contents)
	// ios::app(Append File/Seeks eof before every write)
	// ios::ate(similar to append, but we can move read/write head as required)
	// ios::trunc(Deletes file contents)  // upon testing, fails to delete contents if used by itself or with ios::in.
	// ios::binary(Opens in binary mode, used with | operator and in/out/app/ate/trunc respectively)

	input.open("input.txt", ios::out);  // File "input.txt" opened for output/writing.
	if (input.is_open())  // Check for finding if file opened successfully.
	{
		input << "This is a string passed similar to cout method.\n";
		string txt = "This is a string passed by write method.\n";
		input.write(txt.c_str(), txt.size());  // Specifically used for random access file format.
		input << "This is the third string.\n";

		input.close();  // Necessary for saving changes made to file.
	}
	input.open("input.txt", ios::in);
	if (input.is_open())  // Check for finding if file opened successfully.
	{
		char str[100]{'\0'};
		input.read(str, 40);  // Read by using .read function, does not stop at endline or space characters, 
		// does not automatically put '\0' at end of string, used for random access file format.
		cout << str << "\n\n";
		input >> str;  // Read by using >> operator, it only gets one word, until space character is found, automatically puts '\0'.
		cout << str << "\n\n";
		input.ignore();  // Normal getline problems arise here as well.
		input.getline(str, 100);  // Read by using getline function for cstring, gets whole line, automatically puts '\0', requires max char size.
		cout << str << "\n\n";
		string str1;
		getline(input,str1);  // Read by using getline function for string, gets whole line, best implementation.
		cout << str1 << "\n\n";

		input.close();  // Necessary for saving changes made to file.
	}
	ofstream file("input.txt", ios::app);  // Automatically opens file for writing, use ios::app or ios::ate for append.
	file.close();
	ifstream file1("input.txt");  // Automatically opens file for reading.
	file1.close();
	/*  C++ How to Program 10th Edition:
	• The member functions for repositioning the file-position pointer are seekg (“seek get”) for istream and
		seekp(“seek put”) for ostream. Each istream has a “get pointer” which indicates the byte number in the file
		from which the next input is to occur, and each ostream has a “put pointer” which indicates the
		byte number in the file at which the next output should be placed.
	• The argument to seekg is a long integer. A second argument can be specified to indicate the seek direction,
		which can be ios::beg(the default) for positioning relative to the beginning of a stream,
		ios::cur for positioning relative to the current position in a stream or ios::end for positioning relative to the end of a stream.
	• The file position pointer is an integer value that specifies the location in the file as a number of bytes
		from the file’s starting location(the offset from the beginning of the file).
	• Member functions tellg and tellp are provided to return the current locations of the “get” and “put” pointers, respectively.
	*/



	return 0;
}


