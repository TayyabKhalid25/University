//#include <iostream>
//using namespace std;
//
//int main() 
//{
//	int p1x, p1y, p2x, p2y, p3x, p3y, p4x, p4y, px, py, min_x, max_x, min_y, max_y;
//	cout << "Enter coordinates of Point 1: ";
//    cin >> p1x >> p1y;
//    cout << "Enter coordinates of Point 2: ";
//	cin >> p2x >> p2y;
//    cout << "Enter coordinates of Point 3: ";
//    cin >> p3x >> p3y;
//	cout << "Enter coordinates of Point 4: ";
//	cin >> p4x >> p4y;
//	cout << "Enter coordinates of Point P: ";
//	cin >> px >> py;
//	min_x = max_x = p1x;
//	min_y = max_y = p1y;
//	if (min_x > p2x) {
//		min_x = p2x;
//	}if (min_x > p3x) {
//		min_x = p3x;
//	}if (min_x > p4x) {
//		min_x = p4x;
//	}if (max_x < p2x) {
//		max_x = p2x;
//	}if (max_x < p3x) {
//		max_x = p3x;
//	}if (max_x < p4x) {
//		max_x = p4x;
//	}if (min_y > p2y) {
//		min_y = p2y;
//	}if (min_y > p3y) {
//		min_y = p3y;
//	}if (min_y > p4y) {
//		min_y = p4y;
//	}if (max_y < p2y) {
//		max_y = p2y;
//	}if (max_y < p3y) {
//		max_y = p3y;
//	}if (max_y < p4y) {
//		max_y = p4y;
//	} // end of finding min max values without arrays and subsequently loops.
//	if (px >= min_x && px <= max_x && py >= min_y && py <= max_y) {
//		cout << "Point P lies inside the Rectangle.";
//	} else {
//		cout << "Point P DOES NOT lie inside the Rectangle.";
//	}
//
//	return 0;
//}