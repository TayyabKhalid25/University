#include <iostream>
using namespace std;

bool isPrime(int num)
{
    if (num < 2)  //0 and 1 are not prime
        return false;
    for (int i = 2; i < num/2; i++){
        if (num % i == 0)
        return false;
    }
    return true;
}

bool isFibonacci(int num)
{
    int a = 0, b = 1, temp;
    if (num < 2)  //0 and 1 are fibonacci
        return true;
    while (b < num) {
        temp = a + b;
        a = b;
        b = temp;
    }
    if (num == b)
        return true;
    else
        return false;
}

int MinimumSwapsCount = 0;
void Swap(int& num1, int& num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
    MinimumSwapsCount++;
}

void sort(int arr[], int size)
{
    int fib = 0, prim = 0, nonfibprim = 0;
    for (int i = 0; i < size; i++){  //counting num of fib, prime, nonfib for array boundaries
        if (isFibonacci(arr[i]))
            fib++;
        else if (isPrime(arr[i]))
            prim++;
        else 
            nonfibprim++;
    }
    for (int i = 0; i < size - prim; i++) {  //start of sort
        if (i < fib && !isFibonacci(arr[i])){  //completing fibonacci indexes
            if (isPrime(arr[i])){
                for (int j = size - 1; j >= fib ; j--){  //search prim area first
                    if (isFibonacci(arr[j])){  //if fib
                        Swap(arr[i], arr[j]);
                        break;
                    }
                }
            } else {  // arr[i] is a nonfibprim number
                for (int j = fib; j < size; j++){  // search nonfibprim area first
                    if (isFibonacci(arr[j])){  //if fib
                        Swap(arr[i], arr[j]);
                        break;
                    }
                }
            }
        }else if (i >= fib && isPrime(arr[i])){  //completing nonfibprim indexes
                for (int j = size - 1; j >= size - prim ; j--){  //search prim area 
                    if (!isFibonacci(arr[j]) && !isPrime(arr[j])){  //if nonfibprim
                        Swap(arr[i], arr[j]);
                        break;
                    }
                }
            }
        }
}


int main()
{
    int arr[100], input, size = 0;
    cout << "Enter the Array. Enter -1 to exit: ";
    for (int i = 0; i < 100; i++){
        cin >> input;
        if (input == -1)
            break;
        arr[i] = input;
        size++;
    }
    sort(arr, size);
    cout << "The number of swaps required to get the final array: " << MinimumSwapsCount;
    cout << "\nThe Segregated Array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << ' ';
    cout << endl;


    return 0;
}