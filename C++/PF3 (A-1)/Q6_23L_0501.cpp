//#include <iostream>
//using namespace std;
//
//int main()
//{
//	char p1, p2;
//	cout << "Enter R for rock, P for paper, or S for scissors: \n";
//	cin >> p1 >> p2;
//	p1 = toupper(p1);
//	p2 = toupper(p2);
//	switch (p1)
//	{
//	case 'P': {
//		switch (p2)
//		{
//		case 'R': {
//			cout << "Player 1 Wins!\n";
//		} break;
//		case 'P': {
//			cout << "Draw!\n";
//		} break;
//		case 'S': {
//			cout << "Player 2 Wins!\n";
//		} break;
//		default: {
//			cout << "Wrong letter entered by Player 2.\n";
//		} break;
//		}
//	} break;
//	case 'R': {
//		switch (p2)
//		{
//		case 'S': {
//			cout << "Player 1 Wins!\n";
//		} break;
//		case 'R': {
//			cout << "Draw!\n";
//		} break;
//		case 'P': {
//			cout << "Player 2 Wins!\n";
//		} break;
//		default: {
//			cout << "Wrong letter entered by Player 2.\n";
//		} break;
//		}
//	} break;
//	case 'S': {
//		switch (p2)
//		{
//		case 'P': {
//			cout << "Player 1 Wins!\n";
//		} break;
//		case 'S': {
//			cout << "Draw!\n";
//		} break;
//		case 'R': {
//			cout << "Player 2 Wins!\n";
//		} break;
//		default: {
//			cout << "Wrong letter entered by Player 2.\n";
//		} break;
//		}
//	} break;
//	default: {
//		cout << "Wrong letter entered by Player 1.\n";
//	} break;
//	}
//	cout << "Player 1 entered: " << p1 << "\nPlayer 2 entered: " << p2 << endl;
//}