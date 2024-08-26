#include <iostream>
using namespace std;

int maxMoneyLooted(int *arr, int n)
{
	//Write your code here

	int *result = new int[n];
	result[0] = arr[0];
	result[1] = max(arr[0], arr[1]);

	for(int i = 2; i < n; i++){
		result[i] = max(arr[i] + result[i-2], result[i-1]);
	}
	return result[n-1];
}

int main()
{
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cout << maxMoneyLooted(arr, n);

	delete[] arr;
}