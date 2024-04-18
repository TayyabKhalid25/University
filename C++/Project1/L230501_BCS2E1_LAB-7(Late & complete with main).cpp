#include <iostream>
#include <string>
using namespace std;

// Part 1:
class Complex {
private:
	int real;
	int imaginary;


public:

	Complex(int real = 0, int imaginary = 0) {
		this->real = real;
		this->imaginary = imaginary;
	}

	Complex(const Complex& rhs) {
		this->real = rhs.real;
		this->imaginary = rhs.imaginary;
	}

	~Complex() { cout << "Destructor called of Complex for " << this << endl; }
	// Asuming getter setters nd other functions are not necessary.
	
	Complex operator+(Complex& rhs) {
		return Complex(this->real + rhs.real, this->imaginary + rhs.imaginary);
	}

	Complex operator-(Complex& rhs) {
		return Complex(this->real - rhs.real, this->imaginary - rhs.imaginary);
	}
	
	Complex operator*(Complex& rhs) {
		int x = this->real, y = this->imaginary, a = rhs.real, b = rhs.imaginary;
		return Complex((a*x)-(b*y), (b*x)+(a*y));
	}

	friend ostream& operator<<(ostream& out, const Complex& rhs) {
		out << rhs.real;
		if (rhs.imaginary != 0) {
			if (rhs.imaginary > 0)
				out << " + ";
			else
				out << " - ";
			out << rhs.imaginary << 'i';
		}
		return out;
	}

	friend istream& operator>>(istream& in, Complex& rhs) {
		in >> rhs.real >> rhs.imaginary;
		return in;
	}
};

// Part 2:
class Time {
private:
	int hours;
	int minutes;
	int seconds;

	// Overflow Handler:
	void OverflowHandle(Time& obj) {
		if (obj.seconds >= 60) {
			obj.seconds -= 60;
			obj.minutes++;
		}
		if (obj.minutes >= 60) {
			obj.minutes -= 60;
			obj.hours++;
		}
		if (obj.hours >= 24)
			obj.hours -= 24;
	}

	// Underflow Handler:
	void UnderflowHandle(Time& obj) {
		if (obj.seconds < 0) {
			obj.seconds += 60;
			obj.minutes--;
		}
		if (obj.minutes < 0) {
			obj.minutes += 60;
			obj.hours--;
		}
		if (obj.hours < 0)
			obj.hours += 24;
	}

public:

	Time(int hours = 0, int minutes = 0, int seconds = 0) {
		// Assuming time is passed with correct range.
		this->hours = hours;
		this->minutes = minutes;
		this->seconds = seconds;
	}

	Time(const Time& rhs) {
		this->hours = rhs.hours;
		this->minutes = rhs.minutes;
		this->seconds = rhs.seconds;
	}

	~Time() { cout << "Destructor called of Time for " << this << endl; }
	// Asuming getter setters nd other functions are not necessary.

	Time operator+(const Time& rhs) {
		Time temp(*this);
		temp.seconds += rhs.seconds;
		temp.minutes += rhs.minutes;
		temp.hours += rhs.hours;
		OverflowHandle(temp);

		return temp;
	}

	Time operator-(const Time& rhs) {
		Time temp(*this);
		temp.seconds -= rhs.seconds;
		temp.minutes -= rhs.minutes;
		temp.hours -= rhs.hours;
		UnderflowHandle(temp);

		return temp;
	}

	Time& operator++() {
		this->seconds++;
		OverflowHandle(*this);
		return *this;
	}

	Time& operator--() {
		this->seconds--;
		UnderflowHandle(*this);
		return *this;
	}

	bool operator==(const Time& rhs) {
		return (this->seconds == rhs.seconds && this->minutes == rhs.minutes && this->hours == rhs.hours);
	}

	bool operator!=(const Time& rhs) {
		return (!(*this == rhs));
	}

	friend ostream& operator<<(ostream& out, const Time& rhs) {
		out << "Hours: " << rhs.hours << " Minutes: " << rhs.minutes << " Seconds: " << rhs.seconds;
		return out;
	}

};

// Part 3:
class Distance {  
private:
	float meters;

public:
	Distance(float meters = 0.0f) {
		this->meters = meters;
	}

	Distance(const Distance& rhs) {
		this->meters = rhs.meters;
	}

	~Distance() { cout << "Destructor called of Distance for " << this << endl; }
	// Asuming getter setters nd other functions are not necessary.

	bool operator<(const Distance& rhs) { return (this->meters < rhs.meters); }
	bool operator>(const Distance& rhs) { return (this->meters > rhs.meters); }
	bool operator<=(const Distance& rhs) { return (this->meters <= rhs.meters); }
	bool operator>=(const Distance& rhs) { return (this->meters >= rhs.meters); }
	void operator+=(const Distance& rhs) { this->meters += rhs.meters; }
	void operator-=(const Distance& rhs) { this->meters -= rhs.meters; }
	friend ostream& operator<<(ostream& out, const Distance& rhs) {
		out << rhs.meters;
		return out;
	}
};

// Part 4:
class Matrix {
private:
	int rows;
	int cols;
	int** matrix;

public:

	Matrix(int rows = 0, int cols = 0, bool populate = 1) {
		this->rows = rows;
		this->cols = cols;
		this->matrix = 0;
		if (rows){  // != 0
			// Declare Matrix
			this->matrix = new int* [rows];
			for (int i = 0; i < this->rows; i++)
				this->matrix[i] = new int[this->cols];
			// Populate matrix.
			if (populate){
				for (int i = 0; i < this->rows; i++) {
					for (int j = 0; j < this->cols; j++) {
						cout << "Enter Value[" << i << ", " << j << "]: ";
						cin >> this->matrix[i][j];
					}
				}
			}
		}
	}

	Matrix(const Matrix& rhs) {
		this->rows = rhs.rows;
		this->cols = rhs.cols;
		this->matrix = 0;
		if (rows){  // != 0
			// Declare Matrix
			this->matrix = new int* [this->rows];
			for (int i = 0; i < this->rows; i++)
				this->matrix[i] = new int[this->cols];
			// Populate this->matrix.
			for (int i = 0; i < this->rows; i++){
				for (int j = 0; j < this->cols; j++){
					this->matrix[i][j] = rhs.matrix[i][j];
				}
			}
		}
	}

	~Matrix() { 
		cout << "Destructor called of Matrix for " << this << endl; 
		if (this->matrix){
			for (int i = 0; i < this->rows; i++){
				if (this->matrix[i])
					delete[] this->matrix[i];
			}
			delete[] this->matrix;
		}
	}
	// Asuming getter setters nd other functions are not necessary.
	Matrix operator*(const Matrix& rhs) {
		if (this->cols == rhs.rows) {
			Matrix result(this->rows, rhs.cols, false);
			for (int i = 0; i < this->rows; ++i) {
				for (int j = 0; j < rhs.cols; ++j) {
					result.matrix[i][j] = 0;
					for (int k = 0; k < rhs.rows; ++k) {
						result.matrix[i][j] += this->matrix[i][k] * rhs.matrix[k][j];
					}
					cout << result.matrix[i][j] << "\t";
				}
				cout << endl;
			}
			return result;
		}
		else
			cout << "Unable to do multiplication.\n";
		return Matrix();  // empty matrix.
	}

	friend ostream& operator<<(ostream& out, const Matrix& rhs) {
		for (int i = 0; i < rhs.rows; i++){
			for (int j = 0; j < rhs.cols; j++){
				out << rhs.matrix[i][j] << ' ';
			}
			out << endl;
		}
		return out;
	}

};

// Part 5:
class FlagRegister {
private:
	unsigned int bits;

public:
	FlagRegister(unsigned int bits = 0) {
		this->bits = bits;
	}

	FlagRegister(const FlagRegister& rhs) {
		this->bits = rhs.bits;
	}

	~FlagRegister() { cout << "Destructor called of FlagRegister for " << this << endl; }
	// Asuming getter setters nd other functions are not necessary.

	FlagRegister operator&(const FlagRegister& rhs) {
		return FlagRegister(this->bits & rhs.bits); 
	}
	FlagRegister operator|(const FlagRegister& rhs) {
		return FlagRegister(this->bits | rhs.bits); 
	}
	FlagRegister operator^(const FlagRegister& rhs) { 
		return FlagRegister(this->bits ^ rhs.bits); 
	}

	friend ostream& operator<<(ostream& out, const FlagRegister& rhs) {
		out << rhs.bits;
		return out;
	}

};



int main() {
	Complex num1;
	Complex num2;
	cout << "Enter real nd imaginary for two numbers respectively:\n";
	cin >> num1 >> num2;
	cout << num1 + num2 << endl << num1 - num2 << endl << num1 * num2 << endl;

	Time time1(10, 20, 59);
	Time time2(20, 40, 40);
	cout << time1 + time2 << endl << time1 - time2 << endl << ++time1 << endl << --time1 << endl << (time1 == time2) << endl << (time1 != time2) << endl;

	Distance d1(20);
	Distance d2(40);
	Distance d3(40);
	cout << (d1 < d2) << endl << (d1 > d2) << endl << (d2 <= d3) << endl << (d2 >= d3) << endl;
	// should be 1, 0, 1, 1
	d1 += 20;
	cout << d1 << endl;
	d1 -= 1;
	cout << d1 << endl;
	// should be 40, 39

	Matrix mat1(2, 3);
	Matrix mat2(3, 2);
	cout << mat1 * mat2 << endl << mat1 * mat1 << endl;

	FlagRegister bits1(1);
	FlagRegister bits2(2);

	cout << (bits1 & bits2) << endl << (bits1 | bits2) << endl << (bits1 ^ bits2) << endl;
	// should be 0, 3, 3

	return 0;
}