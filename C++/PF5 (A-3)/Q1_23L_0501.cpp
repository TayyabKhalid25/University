#include <iostream>
using namespace std;

bool findDuplicate(int Triplets[],int i, int j, int k)
{
    for (int x = 0; x < 20; x++)
	{
		if (Triplets[x] == i+j+k)
			return true;
	}
	return false;
}

int main()
{
    int arr[] = {9,4,54,23,54,-23,0,54,5,8}, Triplets[20];
    int N = sizeof(arr)/sizeof(arr[0]), input, count = 0;
    cout << "Enter an Integer Number: ";
    cin >> input;
    for(int i = 0; i < N; i++){
        for (int j = i+1; j < N; j++){
            for (int k = j+1; k < N; k++){
                if (arr[i]+arr[j]+arr[k] == input && !findDuplicate(Triplets,i,j,k)){
                    cout << arr[i] << ", " << arr[j] << " and " << arr[k] << endl;
                    Triplets[count] = i + j + k;
                    count++;
                }
            }
        }    
    }


    return 0;
}