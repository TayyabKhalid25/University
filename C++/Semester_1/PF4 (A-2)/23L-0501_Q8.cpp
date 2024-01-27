#include <iostream>
using namespace std;

int main()
{
    int byear, bmonth, bday, cyear, cmonth, cday;
    bool validdate1, validdate2;
    do  // Part I: Validity of Dates
    {
        validdate1 = validdate2 = true;
        cout << "Enter the year of birth: ";
        cin >> byear;
        cout << "Enter the month of birth: ";
        cin >> bmonth;
        cout << "Enter the day of birth: ";
        cin >> bday;
        cout << "Enter the current year: ";
        cin >> cyear;
        cout << "Enter the current month: ";
        cin >> cmonth;
        cout << "Enter the current day: ";
        cin >> cday;
        if (cyear < 0 || cmonth < 1 || cmonth > 12 || cday < 1 || cday > 31 || byear < 0 || bmonth < 1 || bmonth > 12 || bday < 1 || bday > 31)
            validdate1 = validdate2 = false;
        else{
            if (bmonth == 4 || bmonth == 6 || bmonth == 9 || bmonth == 11)
                validdate1 = (bday <= 30);
            if (cmonth == 4 || cmonth == 6 || cmonth == 9 || cmonth == 11)
                validdate2 = (cday <= 30);
            if (bmonth == 2) {
                if ((byear % 4 == 0 && byear % 100 != 0) || (byear % 400 == 0)) {
                    validdate1 = (bday <= 29);
                }
                else {
                    validdate1 = (bday <= 28);
                }
            }
            if (cmonth == 2) {
                if ((cyear % 4 == 0 && cyear % 100 != 0) || (cyear % 400 == 0)) {
                    validdate1 = (cday <= 29);
                }
                else {
                    validdate1 = (cday <= 28);
                }
            }
        }
        if (validdate1 == false || validdate2 == false)
            cout << "Invalid dates entered.\n";
    } while (validdate1 == false || validdate2 == false);
    // Part II: Calculating Age
    int ayear, amonth, aday;
    if (cday < bday) {
        if (cmonth == 5 || cmonth == 7 || cmonth == 10 || cmonth == 12) 
            cday += 30;
        else if (cmonth == 3) {
            if ((cyear % 4 == 0 && cyear % 100 != 0) || (cyear % 400 == 0)) 
                cday += 29;
            else
                cday += 28;
        } else
            cday += 31;
        cmonth -= 1;
    }
    if (cmonth < bmonth) {
        cmonth += 12;
        cyear -= 1;
    }
    aday = cday - bday;
    amonth = cmonth - bmonth;
    ayear = cyear - byear;
    cout << "The age is " << ayear << " years " << amonth << " months " << aday << " days.\n";
	return 0;
}