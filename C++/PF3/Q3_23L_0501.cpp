//#include <iostream>
//using namespace std;
//
//int main()
//{
//    int number, divisor, currentnum, digits;
//    cout << "Enter a number of maximum 6 digits: ";
//    cin >> number;
//    if (number >= 1000000 || number < 0) {
//        cout << "Wrong Input.\n";
//    } else if (number >= 100000) {
//        divisor = 100000;  // determines which digit is being extracted.
//        digits = 6;  // determines amount of times loop will run.
//    } else if (number >= 10000) {
//        divisor = 10000;
//        digits = 5;
//    } else if (number >= 1000) {
//        divisor = 1000;
//        digits = 4;
//    } else if (number >= 100) {
//        divisor = 100;
//        digits = 3;
//    } else if (number >= 10) {
//        divisor = 10;
//        digits = 2;
//    } else {
//        divisor = 1;
//        digits = 1;
//    }
//    for (int i{ 0 }; i < digits; i++) {
//        currentnum = number / divisor % 10;  //extracts digit.
//        switch (currentnum)
//        {
//        case 0: {
//            cout << "Zero ";
//        } break;
//        case 1: {
//            cout << "One ";
//        } break;
//        case 2: {
//            cout << "Two ";
//        } break;
//        case 3: {
//            cout << "Three ";
//        } break;
//        case 4: {
//            cout << "Four ";
//        } break;
//        case 5: {
//            cout << "Five ";
//        } break;
//        case 6: {
//            cout << "Six ";
//        } break;
//        case 7: {
//            cout << "Seven ";
//        } break;
//        case 8: {
//            cout << "Eight ";
//        } break;
//        case 9: {
//            cout << "Nine ";
//        } break;
//        }
//        divisor /= 10;  // extracts next digit in next loop.
//    }
//    return 0;
//}
