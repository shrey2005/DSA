#include <bits/stdc++.h>
using namespace std;

int countMinStepsToOne(int n)
{
	//Write your code here
	if(n <= 1){
		return 0;
	}

	int decrementValue = countMinStepsToOne(n - 1);

	int divideByTwo = INT_MAX;
	if(n % 2 == 0){
		divideByTwo = countMinStepsToOne(n / 2);
	}

	int divideByThree = INT_MAX;
	if(n % 3 == 0){
		divideByThree = countMinStepsToOne(n / 3);
	}

	int smallAns = min(decrementValue, min(divideByTwo, divideByThree));
	return smallAns + 1;
}

int main()
{
	int n;
	cin >> n;
	cout << countMinStepsToOne(n);
}