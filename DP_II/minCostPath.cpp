#include <bits/stdc++.h>
using namespace std;

int minCostPath_DP(int **input, int m, int n){
	int **output = new int*[m];
	for(int i = 0; i < m; i++){
		output[i] = new int[n];
	}

	output[m-1][n-1] = input[m-1][n-1];

	for(int i = n-2; i >= 0; i--){
		output[m-1][i] = output[m-1][i+1] + input[m-1][i];
	}

	for(int i = m - 2; i >= 0 ; i--){
		output[i][n-1] = output[i+1][n-1] + input[i][n-1];
	}

	for(int i = m - 2; i >= 0; i--){
		for(int j = n - 2; j >= 0; j--){
			output[i][j] = min(output[i][j+1], min(output[i+1][j+1], output[i+1][j])) + input[i][j];
		}
	}

	return output[0][0];
}

int minCostPathHelper(int **input, int x, int y, int m, int n){
	if(x == m - 1 && y == n - 1){
		return input[x][y];
	}

	if(x >= m || y >= n){
		return INT_MAX;
	}
	
	int right = minCostPathHelper(input, x, y + 1, m, n);

	int diagonal = minCostPathHelper(input, x + 1, y + 1, m, n);

	int down = minCostPathHelper(input, x + 1, y, m, n);

	int findMin = min(right, min(down, diagonal)) + input[x][y];
	return findMin;
}

int minCostPathHelperMemo(int **input, int x, int y, int m, int n, int **output){
	if(x == m - 1 && y == n - 1){
		return input[x][y];
	}

	if(x >= m || y >= n){
		return INT_MAX;
	}
	 
	if(output[x][y] != -1){
		return output[x][y];
	}
	
	int right = minCostPathHelper(input, x, y + 1, m, n);

	int diagonal = minCostPathHelper(input, x + 1, y + 1, m, n);

	int down = minCostPathHelper(input, x + 1, y, m, n);

	int findMin = min(right, min(down, diagonal)) + input[x][y];

	output[x][y] = findMin;
	return findMin;
}
int minCostPath(int **input, int m, int n)
{

	int result = minCostPath_DP(input, m, n);
	return result;
}

int main()
{
	int **arr, n, m;
	cin >> n >> m;
	arr = new int *[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << minCostPath(arr, n, m) << endl;
}