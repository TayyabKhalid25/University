//#include <iostream>
//using namespace std;
//
//int main()
//{
//    // (A):
//    char out{'*'};
//    for (int i{ 1 }; i < 11; i++) {
//        for (int x{ 0 }; x < i; x++) {
//            cout << out;
//            if (out == '\n') {
//                x = i; // exit loop after running endline once.
//            }
//        }
//        if (out == '*') {
//            out = '\n';
//            i--;  // run through same instance again, but with newline as output.
//        }
//        else {  // if out == '\n'
//            out = '*';
//        }
//    }
//    // (B):
//    out = '*';
//    for (int i{ 10 }; i > 0; i--) {
//        for (int x{ 0 }; x < i; x++) {
//            cout << out;
//            if (out == '\n') {
//                x = i;
//            }
//        }
//        if (out == '*') {
//            out = '\n';
//            i++;
//        }
//        else {
//            out = '*';
//        }
//    }
//    // (C):
//    out = ' ';
//    int x{ 0 }, y{0}; // 0 spaces in beginning.
//    for (int i{ 0 }; i < 10; i++) {
//        x = 0;
//        while (x < y)
//        {
//            cout << out;
//            x++;
//        }
//        if (out == ' ') {
//            out = '*';
//            y = 10 - i;
//            i--;
//        }
//        else if (out == '*') { 
//            out = '\n';
//            y = 1; // better way of exiting loop after endline.
//            i--;
//        }
//        else {  // if out == '\n'
//            out = ' ';
//            y = i + 1;
//        }
//    }
//    // (D):
//    out = ' ';
//    x = 0, y = 9;
//    for (int i{ 0 }; i < 10; i++) {
//        x = 0;
//        while (x < y)
//        {
//            cout << out;
//            x++;
//        }
//        if (out == ' ') {
//            out = '*';
//            y = i + 1;
//            i--;
//        }
//        else if (out == '*') {
//            out = '\n';
//            y = 1; 
//            i--;
//        }
//        else {  // if out == '\n'
//            out = ' ';
//            y = 8-i;
//        }
//    }
//    return 0;
//}