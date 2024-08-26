#include <cstring>
#include <iostream>
using namespace std;

int knapsackHelper(int *weights, int *values, int n, int maxWeight, int **arr){
	if(n == 0 || maxWeight == 0){
		return 0;
	}
	
	if(arr[n][maxWeight] != -1){
	    return arr[n][maxWeight];
	}
	
	if(weights[0] > maxWeight){
		arr[n][maxWeight] =  knapsackHelper(weights + 1, values + 1, n - 1, maxWeight, arr);
    } 
	else {
        int smallOutput2 =  knapsackHelper(weights + 1, values + 1, n - 1,maxWeight - weights[0], arr) + values[0];
        int smallOutput1 = knapsackHelper(weights + 1, values + 1, n - 1, maxWeight, arr);
        int result = max(smallOutput1, smallOutput2);
        arr[n][maxWeight] = result;
	}
    return arr[n][maxWeight];
}

int knapsack_DP(int *weights, int *values, int n, int maxWeight){
	int **ans = new int*[n+1];
	for(int i = 0; i <= n; i++){
		ans[i] = new int[maxWeight+1];
	}

	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= maxWeight; j++){
			if(i == 0 || j == 0){
				ans[i][j] = 0;
			}
			else if(weights[i - 1] <= j){
				int ans1 = ans[i - 1][j-weights[i - 1]] + values[i- 1];
				int ans2 = ans[i - 1][j];
				int result = max(ans1, ans2);
				ans[i][j] = result;
			}
			else{				
				ans[i][j] = ans[i-1][j];
			}
		}
	}

	return ans[n][maxWeight];
}

int knapsack(int *weights, int *values, int n, int maxWeight)
{
	//write your code here
	// int **arr = new int*[n+1];
	
	// for(int i = 0; i <= n; i++){
	//     arr[i] = new int[maxWeight+1];
	// 	for(int j = 0; j <= maxWeight; j++){
	// 		arr[i][j] = -1;
	// 	}
	// }
	// int result = knapsackHelper(weights, values, n, maxWeight, arr);

	int result = knapsack_DP(weights, values, n, maxWeight);
	return result;
}

int main() {
    int n;
    cin >> n;
    int* wt = new int[n];
    int* val = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    for (int j = 0; j < n; j++) {
        cin >> val[j];
    }

    int w;
    cin >> w;

    cout << knapsack(wt, val, n, w) << "\n";

    delete[] wt;
    delete[] val;
}