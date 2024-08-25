#include <bits/stdc++.h>
using namespace std;

int minStepHelper(int *ans, int n){
	if(n <= 1){
		return 0;
	}

	if(ans[n] != -1){
		return ans[n];
	}

	int x = minStepHelper(ans,n - 1);

	int y = INT_MAX, z = INT_MAX;
	if( n % 2 == 0){
		y = minStepHelper(ans, n / 2);
	}

	if( n % 3 == 0){
		z = minStepHelper(ans, n / 3);
	}

	int smallAns = min(x, min(y, z)) + 1;
	ans[n] = smallAns;
	return smallAns;
}
int countStepsToOne(int n)
{
	//Write your code here
	int *ans = new int[n + 1];

	for(int i = 0; i <= n; i++){
		ans[i] = -1;
	} 

	int count = minStepHelper(ans, n);

	return count;
}

int main()
{
	int n;
	cin >> n;
	cout << countStepsToOne(n);
}