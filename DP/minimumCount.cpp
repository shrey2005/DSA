#include <bits/stdc++.h>
#include<vector>
using namespace std;

int minCountHelper(vector<int> &arr, int n){
	if(n == 0){
		return 0;
	}

	if(arr[n] != -1){
		return arr[n];
	}

	int minCount = n;

	for(int i = 1; i * i <= n; i++){
		int square = i * i;
		int minVal = minCountHelper(arr, n - square) + 1;
		minCount = min(minCount, minVal);
	}
	arr[n] = minCount;
	return arr[n];
}
int minCount(int n)
{
	//Write your code here
	vector<int> arr(n+1, -1);
	return minCountHelper(arr, n);
}

int main()
{
	int n;
	cin >> n;
	cout << minCount(n);
}