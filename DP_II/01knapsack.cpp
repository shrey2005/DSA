#include <iostream>
using namespace std;

int knapsackHelper(int *weights, int *values, int n, int maxWeight){

	if(n == 0 || maxWeight == 0){
		return 0;
	}
	
	if(weights[0] > maxWeight){
		return  knapsackHelper(weights + 1, values + 1, n - 1, maxWeight);
	}
	int	smallOutput2 = knapsackHelper(weights + 1, values + 1, n - 1, maxWeight - weights[0]) + values[0];
	int smallOutput1 = knapsackHelper(weights + 1, values + 1, n - 1, maxWeight);
	return max(smallOutput1, smallOutput2);
}

int knapsack(int *weights, int *values, int n, int maxWeight)
{
	//write your code here
	int result = knapsackHelper(weights, values, n, maxWeight);
	return result;
}

int main()
{
	int n;
	cin >> n;

	int *weights = new int[n];
	int *values = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> weights[i];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> values[i];
	}

	int maxWeight;
	cin >> maxWeight;

	cout << knapsack(weights, values, n, maxWeight) << endl;

	delete[] weights;
	delete[] values;
}