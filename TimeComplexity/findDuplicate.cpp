#include <iostream>
using namespace std;

int findDuplicate(int *arr, int n)
{
    //Write your code here
    int *countArr = new int[n - 1];
    for(int i = 0; i < n; i++){
        countArr[arr[i]]++;
    }

    for(int i = 0; i < n; i++){
        if(countArr[arr[i]] == 2){
            return arr[i];
        }
    }
}

int main()
{
	int t;
	cin >> t;
	
	while (t--)
	{
		int size;
		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cout << findDuplicate(input, size) << endl;
	}

	return 0;
}