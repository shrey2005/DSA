#include <iostream>
#include<vector>
using namespace std;

int countWaysToMakeChange(int denominations[], int numDenominations, int value){
	if(numDenominations == 0 || value == 0){
	//Write your code here
		return 0;
	}

	vector<int> dp(value + 1,  0);
	
	dp[0] = 1;

	 for (int i = 0; i < numDenominations; i++) {
        for (int j = denominations[i]; j <= value; j++) {
            dp[j] += dp[j - denominations[i]];
        }
    }

	return dp[value];
}

int main()
{

	int numDenominations;
	cin >> numDenominations;
	
	int *denominations = new int[numDenominations];

	for (int i = 0; i < numDenominations; i++)
	{
		cin >> denominations[i];
	}

	int value;
	cin >> value;

	cout << countWaysToMakeChange(denominations, numDenominations, value);

	delete[] denominations;
}