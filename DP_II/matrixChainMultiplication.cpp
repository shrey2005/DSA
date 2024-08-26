#include <iostream>
using namespace std;

#include<climits>
#include<vector>
int matrixChainMultiplicationHelper(int *arr, int s, int e, vector<vector<int>> &dp) {
    if (s == e) {
        return 0; // No cost if there's only one matrix
    }

    if (dp[s][e] != -1) {
        return dp[s][e]; // Return already computed result
    }

    int minCost = INT_MAX;

    for (int i = s; i < e; i++) {
        int cost = matrixChainMultiplicationHelper(arr, s, i, dp) +
                   matrixChainMultiplicationHelper(arr, i + 1, e, dp) +
                   arr[s - 1] * arr[i] * arr[e];
        minCost = min(minCost, cost);
    }

    dp[s][e] = minCost; // Store the computed result
    return minCost;
}

int matrixChainMultiplication(int* arr, int n) {
    vector<vector<int>> dp(n, vector<int>(n + 1, -1)); 
    return matrixChainMultiplicationHelper(arr, 1, n, dp); // Corrected the call with bounds 1 to n-1
}


int main() {
    int n;
    cin >> n;
    int* arr = new int[n+1];

    for (int i = 0; i <= n; i++) {
        cin >> arr[i];
    }

    cout << matrixChainMultiplication(arr, n);

    delete[] arr;
}