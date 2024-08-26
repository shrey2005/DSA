#include <iostream>
using namespace std;

int findMaxSquareWithAllZeros(int **arr, int n, int m)
{
	// return maxZero;
	if (n == 0 || m == 0) {
        return 0;
    }

    // Allocate memory for ans array
    int **ans = new int*[n];
    for (int i = 0; i < n; i++) {
        ans[i] = new int[m]();
    }

    // Initialize the first row and column based on arr
    for (int i = 0; i < n; i++) {
        ans[i][0] = (arr[i][0] == 0) ? 1 : 0;
    }
    for (int j = 0; j < m; j++) {
        ans[0][j] = (arr[0][j] == 0) ? 1 : 0;
    }

    // Find the largest square submatrix with all zeros
    int maxZero = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (arr[i][j] == 0) {
				int min1 = ans[i-1][j-1];
				int min2 = ans[i-1][j];
				int min3 = ans[i][j-1];
                ans[i][j] = min(min1, min(min2, min3)) + 1;
                maxZero = max(maxZero, ans[i][j]);
            } else {
                ans[i][j] = 0;
            }
        }
    }

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        delete[] ans[i];
    }
    delete[] ans;

    return maxZero;
}



int main()
{
	int **arr, n, m, i, j;
	cin >> n >> m;
	arr = new int *[n];
	
	for (i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	cout << findMaxSquareWithAllZeros(arr, n, m) << endl;

	delete[] arr;

	return 0;
}