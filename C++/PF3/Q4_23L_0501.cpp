//#include <iostream>
//using namespace std;
//
//int main()
//{
//    double p1x{ 0 }, p1y{ 0 }, p2x{ 2 }, p2y{ 0 }, p3x{ 1 }, p3y{ sqrt(3) }, length1, length2, length3, checkright;
//    cout << "Enter coordinates of Point 1: ";
//    cin >> p1x >> p1y;
//    cout << "Enter coordinates of Point 2: ";
//    cin >> p2x >> p2y;
//    cout << "Enter coordinates of Point 3: ";
//    cin >> p3x >> p3y;
//    length1 = sqrt(pow(p2x - p1x, 2) + pow(p2y - p1y, 2));
//    length2 = sqrt(pow(p2x - p3x, 2) + pow(p2y - p3y, 2));
//    length3 = sqrt(pow(p3x - p1x, 2) + pow(p3y - p1y, 2));
//    for (int i = 0; i < 2; i++) {  // Code for sorting.
//                if (length1 > length2) {
//                    length1 += length2;
//                    length2 = length1 - length2;
//                    length1 -= length2;  // Procedure for swap of int values without temp variable.
//                }
//                if (length2 > length3) {
//                    length2 += length3;
//                    length3 = length2 - length3;
//                    length2 -= length3;
//                }
//    }//since calculations in programming arent always precise, we should round number.
//    checkright = round(pow(length3, 2) - (pow(length1, 2) + pow(length2, 2)));
//    if (checkright == 0) {
//        cout << "These are coordinates of Right Angle Triangle.\n";
//    } else if (length1 == length2 && length2 == length3 && length1 == length3) {
//        cout << "These are coordinates of Equilateral Triangle.\n";
//    } else if (length1 == length2 || length2 == length3 || length1 == length3) {
//        cout << "These are coordinates of Isoceles Triangle.\n";
//    } else {
//        cout << "These are coordinates of Scalene Triangle.\n";
//    }
//
//   
//
//    return 0;
//}
