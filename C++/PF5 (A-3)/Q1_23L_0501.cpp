#include <iostream>
using namespace std;

int main()
{
    int arr[] = {9,4,54,23,54,-23,0,54,5,8};
    int N = sizeof(arr)/sizeof(arr[0]), input;
    cout << "Enter an Integer Number: ";
    cin >> input;
    for(int i = 0; i < N - 2; i++){
        for (int j = i+1; j < N - 1; j++){
            for (int k = j+1; k < N; k++){
                if (arr[i]+arr[j]+arr[k] == input)
                    cout << arr[i] << ", " << arr[j] << " and " << arr[k] << endl;
            }
        }    
    }


    return 0;
}