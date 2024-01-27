//#include <iostream>
//#include <iomanip>  // library for output manipulation. purely aesthetic, OCD
//using namespace std;
//
//int main()
//{
//     Menu:
//    cout << left << setw(7) << "Code" << setw(20) << "Meal" << setw(15) << "Per kg Price" << endl; // setw used for better table output
//    cout << setw(7) << "1" << setw(20) << "Chicken Handi" << setw(15) << "1800" << endl;
//    cout << setw(7) << "2" << setw(20) << "Chicken Karahi" << setw(15) << "2000" << endl;
//    cout << setw(7) << "3" << setw(20) << "Chicken Tikka" << setw(15) << "2200" << endl;
//    cout << setw(7) << "4" << setw(20) << "Chicken Haleem" << setw(15) << "500" << endl;
//    cout << setw(7) << "5" << setw(20) << "Creamy Chicken" << setw(15) << "2500" << endl;
//    cout << "*******************************************************\n";
//    Selection:
//    int option, currency;
//    double quantity, mealprice{ 0 }, salestax{ 0 }, total;
//    cout << "Please select a dish using its code: ";
//    cin >> option;
//    cout << "*******************************************************\n";
//    if (option > 5 || option < 1) {
//        cout << "Invalid code entered.\n";
//    } else {
//        cout << "Please select quantity of the dish in Kgs: ";
//        cin >> quantity;
//        cout << "*******************************************************\n";
//        if (quantity <= 0) {
//            cout << "Invalid quantity entered.\n";
//        } else {
//            cout << "Please select currency of payment:\n1: Pakistani Rupees\n2: Dollars\n3: Euros\nOption: ";
//            cin >> currency;
//            cout << "*******************************************************\n";
//            if (currency > 3 || currency < 1) {
//                cout << "Invalid option entered.\n";
//            } else {
//                switch (option) {
//                case 1: {
//                    mealprice = 1800 * quantity;
//                } break;
//                case 2: {
//                    mealprice = 2000 * quantity;
//                } break;
//                case 3: {
//                    mealprice = 2200 * quantity;
//                } break;
//                case 4: {
//                    mealprice = 500 * quantity;
//                } break;
//                case 5: {  
//                    mealprice = 2500 * quantity;
//                } break;
//                }
//                if (mealprice > 1000 && mealprice <= 3000) {
//                    salestax = mealprice * 0.02;
//                } else if (mealprice > 3000) {
//                    salestax = mealprice * 0.05;
//                }
//                total = mealprice + salestax;
//                switch (currency) {
//                case 1: {
//                    cout << "Meal Price: Rs." << mealprice << endl;
//                    cout << "Sales Tax: Rs." << salestax << endl;
//                    cout << "Total Price: Rs." << total << endl;
//                } break;
//                case 2: {
//                    cout << "Meal Price: $" << mealprice/165 << endl;
//                    cout << "Sales Tax: $" << salestax/165 << endl;
//                    cout << "Total Price: $" << total/165 << endl;
//                } break;
//                case 3: {
//                    cout << "Meal Price: " << mealprice/193 << " Euros" << endl;
//                    cout << "Sales Tax: " << salestax/193 << " Euros" << endl;
//                    cout << "Total Price: " << total/193 << " Euros" << endl;
//                } break;
//                }
//            }
//        }
//    }
//
//    return 0;
//}
