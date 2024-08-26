#include <iostream>
using namespace std;

// #include <climits>
int longestIncreasingSubsequence(int* arr, int n) {
	// Write your code here
	int *result = new int[n];

	for(int i = 0; i < n; i++){
		result[i] = 1;
	}
	
	for(int i = 1; i < n; i++){
		for(int j = 0; j < i; j++){
			if(arr[i] > arr[j] && result[i] < result[j] + 1){
				result[i] = result[j] + 1;
			}
		}
	}

	int max = 0;
	for(int i = 0; i < n; i++){
		if( max < result[i]){
			max = result[i];
		}
	}
	return max;
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << longestIncreasingSubsequence(arr, n);
}