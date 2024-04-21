#include <iostream>
using namespace std;

int findEquilibriumIndex(int *arr, int n)
{
    //Write your code here
    int index = -1;
    int ls = 0;
    int rs = 0;
    for(int i = 0; i < n; i++){
        rs += *(arr+i);
    } 
    for(int i = 0; i < n; i++){
        rs = rs - arr[i];
        if(rs == ls){
            index = i;
        }
        ls = ls + arr[i];
    }
    return index;
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

		cout << findEquilibriumIndex(input, size) << endl;

		delete[] input;
	}
	return 0;
}